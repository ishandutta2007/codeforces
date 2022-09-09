#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define mp make_pair
#define pb push_back
#define ll long long
const int N=200050;
const int M=20*N;
int x[M],ls[M],rs[M],tsz,root[N];
void Set(int p, int &c, int ss, int se, int qi)
{
	c=++tsz;x[c]=x[p]+1;ls[c]=ls[p];rs[c]=rs[p];
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[p],ls[c],ss,mid,qi);
	else Set(rs[p],rs[c],mid+1,se,qi);
}
int Get(int c, int ss, int se, int qs, int qe)
{
	if(qs>se || ss>qe || qs>qe) return 0;
	if(qs<=ss && qe>=se) return x[c];
	int mid=ss+se>>1;
	return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
}
int a[N],id[N];
bool comp(int i, int j){ return a[i]>a[j];}
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),id[i]=i;
	sort(id+1,id+1+n,comp);
	for(i=1;i<=n;i++) Set(root[i-1],root[i],1,N,id[i]);
	ll sol=0;
	for(i=1;i<=n;i++)
	{
		int top=n,bot=1,mid,ans=0;
		while(top>=bot)
		{
			mid=top+bot>>1;
			if(a[id[mid]]>=i) ans=mid,bot=mid+1;
			else top=mid-1;
		}
		sol+=Get(root[ans],1,N,i+1,a[i]);
	}
	printf("%lld\n",sol);
	return 0;
}