#include <stdio.h>
#include <algorithm>
using namespace std;
const int N=100050;
const int M=2*N;
int x[M],ls[M],rs[M],clock,root;
int max(int a, int b){ return a>b?a:b;}
void Set(int &c, int ss, int se, int qi, int val)
{
	if(!c) c=++clock;
	x[c]=val;
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,val);
	else Set(rs[c],mid+1,se,qi,val);
}
int Get(int c, int ss, int se, int qs, int qe)
{
	if(ss>qe || qs>se) return 0;
	if(qs<=ss && qe>=se) return x[c];
	int mid=ss+se>>1;
	return max(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
}
int BIT[N];
void Set(int i){ for(;i<N;i+=i&-i) BIT[i]++;}
int Get(int i){ int ret=0;for(;i;i-=i&-i) ret+=BIT[i];return ret;}
pair<int,int> a[N];
int sol[N];
int main()
{
	int n,i,x;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&x);
		a[i].first=x;
		a[i].second=i;
	}
	sort(a+1,a+1+n);
	for(i=n;i;i--)
	{
		if(Get(a[i].second)==0) sol[a[i].first]--;
		if(Get(a[i].second)==1)
		{
			sol[Get(root,1,N,1,a[i].second)]++;
		}
		Set(a[i].second);
		Set(root,1,N,a[i].second,a[i].first);
	}
	int ans=1;
	for(i=1;i<=n;i++)
	{
		if(sol[ans]<sol[i]) ans=i;
	}
	printf("%i\n",ans);
	return 0;
}