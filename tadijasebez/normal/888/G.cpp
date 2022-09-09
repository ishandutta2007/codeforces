#include <stdio.h>
#include <algorithm>
using namespace std;
const int N=200050;
const int M=31*N;
int max(int a, int b){ return a>b?a:b;}
int x[M],mx[M],ls[M],rs[M],clock,root;
void Set(int &c, int lvl, int X, int B)
{
	if(!c) c=++clock,x[c]=0;
	x[c]++;mx[c]=max(mx[c],B);
	if(lvl==-1) return;
	if((X>>lvl)&1) Set(rs[c],lvl-1,X,B);
	else Set(ls[c],lvl-1,X,B);
}
void Set(int X, int B){ Set(root,29,X,B);}
int Y;
void Get(int c, int lvl, int X, int B)
{
	if(lvl==-1) return;
	if((X>>lvl)&1)
	{
		if(x[rs[c]]==0 || mx[rs[c]]<B)
		{
			Y+=1<<lvl;
			Get(ls[c],lvl-1,X,B);
		}
		else Get(rs[c],lvl-1,X,B);
	}
	else
	{
		if(x[ls[c]]==0 || mx[ls[c]]<B)
		{
			Y+=1<<lvl;
			Get(rs[c],lvl-1,X,B);
		}
		else Get(ls[c],lvl-1,X,B);
	}
}
int Get(int X, int B){ Y=0;Get(root,29,X,B);return Y;}
#define ll long long
ll sol;
int a[N];
int min(int a, int b){ return a>b?b:a;}
void Solve(int l, int r, int lvl)
{
	if(lvl<0 || l+1>=r) return;
	int mid=l,i;
	while(mid<r && !((a[mid]>>lvl)&1)) mid++;
	Solve(l,mid,lvl-1);
	Solve(mid,r,lvl-1);
	if(mid==l || mid==r) return;
	int ans=(1<<30)+69;
	for(i=l;i<mid;i++) ans=min(ans,Get(a[i],mid));
	sol+=ans;
}
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=0;i<n;i++) scanf("%i",&a[i]);
	sort(a,a+n);
	for(i=0;i<n;i++) Set(a[i],i);
	Solve(0,n,29);
	printf("%lld\n",sol);
	return 0;
}