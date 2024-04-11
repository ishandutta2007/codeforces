#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200050;
const int M=2*N;
ll sum[M];
int sz[M],ls[M],rs[M],tsz,root;
void Set(int &c, int ss, int se, int qi, int f, ll x)
{
	if(!c) c=++tsz;
	sz[c]+=f;
	sum[c]+=x;
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,f,x);
	else Set(rs[c],mid+1,se,qi,f,x);
}
int GetSZ(int c, int ss, int se, ll k)
{
	if(ss==se) return k>=sum[c]?sz[c]:0;
	int mid=ss+se>>1;
	if(sum[ls[c]]<=k) return sz[ls[c]]+GetSZ(rs[c],mid+1,se,k-sum[ls[c]]);
	else return GetSZ(ls[c],ss,mid,k);
}
ll GetSum(int c, int ss, int se, int k)
{
	if(ss==se) return k>=sz[c]?sum[c]:0;
    int mid=ss+se>>1;
    if(sz[ls[c]]<=k) return sum[ls[c]]+GetSum(rs[c],mid+1,se,k-sz[ls[c]]);
    else return GetSum(ls[c],ss,mid,k);
}
void Clear(){ while(tsz) ls[tsz]=rs[tsz]=sz[tsz]=sum[tsz]=0,tsz--;root=0;}
int id[N],a[N];
bool comp(int i, int j){ return a[i]<a[j];}
void Run()
{
	int n,m,i,j;ll t;
	scanf("%i %i %lld",&n,&m,&t);
	Clear();
	for(i=1;i<=n;i++) scanf("%i",&a[i]),id[i]=i;
	sort(id+1,id+1+n,comp);
	int sol=0,ans=1;
	for(j=1;j<=n;j++)
	{
		i=id[j];
		Set(root,1,n,i,1,a[i]);
		if(j<n && a[i]==a[id[j+1]]) continue;
        int cnt=GetSZ(root,1,n,t/2);
        cnt-=cnt%m;
        ll dbl=GetSum(root,1,n,cnt);
        int tmp=GetSZ(root,1,n,t-dbl);
        tmp=min(tmp,cnt+m);
        if(tmp>sol) sol=tmp,ans=a[i];
	}
	printf("%i %i\n",sol,ans);
}
int main()
{
	int t;scanf("%i",&t);
	while(t--) Run();
	return 0;
}