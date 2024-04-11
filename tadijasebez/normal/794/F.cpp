#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
const int N=100050;
const int K=9;
const int C=10;
const int M=2*N;
int root,tsz,ls[M],rs[M],lzy[M][C],cif[C][N];
ll cnt[M][C];
void Build(int &c, int ss, int se)
{
	if(ss>se) return;
	c=++tsz;
	for(int i=0;i<C;i++) lzy[c][i]=i;
	if(ss==se){ for(int i=0;i<C;i++) cnt[c][i]=cif[i][ss];return;}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	for(int i=0;i<C;i++) cnt[c][i]=cnt[ls[c]][i]+cnt[rs[c]][i];
}
void Push(int c)
{
	vector<ll> sum1(C,0),sum2(C,0);
	for(int i=0;i<C;i++)
	{
		sum1[lzy[c][i]]+=cnt[ls[c]][i];
		sum2[lzy[c][i]]+=cnt[rs[c]][i];
		lzy[ls[c]][i]=lzy[c][lzy[ls[c]][i]];
		lzy[rs[c]][i]=lzy[c][lzy[rs[c]][i]];
	}
	for(int i=0;i<C;i++) cnt[ls[c]][i]=sum1[i],cnt[rs[c]][i]=sum2[i];
	for(int i=0;i<C;i++) lzy[c][i]=i;
}
void Set(int c, int ss, int se, int qs, int qe, int x, int y)
{
	if(qs>qe || qs>se || ss>qe) return;
	if(qs<=ss && qe>=se)
	{
		cnt[c][y]+=cnt[c][x];cnt[c][x]=0;
		for(int i=0;i<C;i++) if(lzy[c][i]==x) lzy[c][i]=y;
		return;
	}
	Push(c);
	int mid=ss+se>>1;
	Set(ls[c],ss,mid,qs,qe,x,y);
	Set(rs[c],mid+1,se,qs,qe,x,y);
	for(int i=0;i<C;i++) cnt[c][i]=cnt[ls[c]][i]+cnt[rs[c]][i];
}
ll ans;
void Get(int c, int ss, int se, int qs, int qe)
{
	if(qs>qe || qs>se || ss>qe) return;
	if(qs<=ss && qe>=se)
	{
		for(int i=0;i<C;i++) ans+=i*cnt[c][i];
		return;
	}
	Push(c);
	int mid=ss+se>>1;
	Get(ls[c],ss,mid,qs,qe);
	Get(rs[c],mid+1,se,qs,qe);
}
int main()
{
	int n,q,i,j,t,l,r,x,y;
	scanf("%i %i",&n,&q);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&x);
		int po=1;
		for(j=0;j<K;j++)
		{
			int tmp=x%10;
			x/=10;
			if(x==0 && tmp==0) break;
			cif[tmp][i]+=po;
			po*=10;
		}
	}
	Build(root,1,n);
	while(q--)
	{
		scanf("%i %i %i",&t,&l,&r);
		if(t==1)
		{
			scanf("%i %i",&x,&y);
			if(x==y) continue;
			Set(root,1,n,l,r,x,y);
		}
		else
		{
			ans=0;
			Get(root,1,n,l,r);
			printf("%lld\n",ans);
		}
	}
	return 0;
}