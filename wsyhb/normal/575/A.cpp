#include<bits/stdc++.h>
using namespace std;
long long K;
int P,N,M;
const int max_N=5e4+5;
int s[max_N];
struct Matrix
{
	int a,b,c,d;
	inline Matrix(int x=0,int y=0,int z=0,int w=0)
	{
		a=x,b=y,c=z,d=w;
	}
	/*
	inline void print()
	{
		fprintf(stderr,"%d %d\n%d %d\n",a,b,c,d);
	}
	*/
}pref[max_N],suff[max_N],ans(0,1,0,0),A;
inline Matrix operator * (const Matrix &p,const Matrix &q)
{
	return Matrix((1ll*p.a*q.a+1ll*p.b*q.c)%P,
	(1ll*p.a*q.b+1ll*p.b*q.d)%P,
	(1ll*p.c*q.a+1ll*p.d*q.c)%P,
	(1ll*p.c*q.b+1ll*p.d*q.d)%P);
}
namespace SegTree
{
	Matrix val[max_N<<2];
	#define ls(p) ((p)<<1)
	#define rs(p) ((p)<<1|1)
	void build(int p,int l,int r)
	{
		if(l==r)
		{
			val[p]=Matrix(0,s[l],1,s[l+1]);
			return;
		}
		int mid=(l+r)>>1;
		build(ls(p),l,mid);
		build(rs(p),mid+1,r);
		val[p]=val[ls(p)]*val[rs(p)];
	}
	void query(int p,int l,int r,int a,int b)
	{
		if(a<=l&&r<=b)
		{
			ans=ans*val[p];
			return;
		}
		int mid=(l+r)>>1;
		if(a<=mid)
			query(ls(p),l,mid,a,b);
		if(b>mid)
			query(rs(p),mid+1,r,a,b);
	}
}
inline void solve(long long l,long long r) // (s[l],s[l+1])...(s[r-1],s[r])
{
//	fprintf(stderr,"l=%lld r=%lld\n",l,r);
	--r;
	if(l>r)
		return;
	if(l/N==r/N)
	{
		SegTree::query(1,0,N-1,l%N,r%N);
//		fprintf(stderr,"ans:\n");
//		ans.print();
		return;
	}
	ans=ans*suff[l%N];
	long long t=r/N-l/N-1;
	A=pref[N-1];
	while(t)
	{
		if(t&1)
			ans=ans*A;
		A=A*A;
		t>>=1;
	}
	ans=ans*pref[r%N];
//	fprintf(stderr,"ans:\n");
//	ans.print();
}
typedef pair<long long,int> plli;
const int max_M=5e4+5;
plli extra[max_M];
int main()
{
//	freopen("data2.in","r",stdin);
//	freopen("data2.out","w",stdout);
	scanf("%lld%d%d",&K,&P,&N);
//	fprintf(stderr,"K=%lld P=%d N=%d\n",K,P,N);
	if(P==1)
	{
		puts("0");
		return 0;
	}
	if(K<2)
	{
		printf("%lld\n",K);
		return 0;
	}
//	fprintf(stderr,"s:");
	for(int i=0;i<N;++i)
	{
		scanf("%d",s+i);
//		fprintf(stderr,"%d%c",s[i],i+1<N?' ':'\n');
	}
	s[N]=s[0];
	pref[0]=Matrix(0,s[0],1,s[1]);
	for(int i=1;i<N;++i)
		pref[i]=pref[i-1]*Matrix(0,s[i],1,s[i+1]);
	suff[N-1]=Matrix(0,s[N-1],1,s[0]);
	for(int i=N-2;i>=0;--i)
		suff[i]=Matrix(0,s[i],1,s[i+1])*suff[i+1];
	/*
	for(int i=0;i<=N-1;++i)
	{
		fprintf(stderr,"i=%d pref[i]:\n",i);
		pref[i].print();
		fprintf(stderr,"i=%d suff[i]:\n",i);
		suff[i].print();
	}
	*/
	SegTree::build(1,0,N-1);
	scanf("%d",&M);
	for(int i=1;i<=M;++i)
		scanf("%lld%d",&extra[i].first,&extra[i].second);
	sort(extra+1,extra+M+1);
	while(M>=1&&extra[M].first>=K)
		--M;
//	fprintf(stderr,"M=%d\n",M);
//	for(int i=1;i<=M;++i)
//		fprintf(stderr,"i=%d %lld %d\n",i,extra[i].first,extra[i].second);
	if(!M)
	{
		solve(0,K-1);
		printf("%d\n",ans.b);
		return 0;
	}
	solve(0,extra[1].first-1);
	for(int i=1;i<=M;++i)
	{
		if(i==1||extra[i-1].first!=extra[i].first-1)
			ans=ans*Matrix(0,s[(extra[i].first-1)%N],1,extra[i].second);
		else
			ans=ans*Matrix(0,extra[i-1].second,1,extra[i].second);
//		fprintf(stderr,"i=%d\nans:\n",i);
//		ans.print();
		if(extra[i].first+1<=K-1&&(i==M||extra[i+1].first!=extra[i].first+1))
			ans=ans*Matrix(0,extra[i].second,1,s[(extra[i].first+1)%N]);
//		fprintf(stderr,"i=%d\nans:\n",i);
//		ans.print();
		if(i<M)
			solve(extra[i].first+1,extra[i+1].first-1);
	}
	solve(extra[M].first+1,K-1);
	printf("%d\n",ans.b);
	return 0;
}