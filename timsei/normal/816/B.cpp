using namespace std;
#include<bits/stdc++.h>
#define N 8000001
#define r(x) scanf("%d",&x)
#define lc no<<1
#define rc no<<1|1
#define getmid int mid=(L[no]+R[no])>>1
int L[N],R[N];
int S[N];
int A[N];
int hh[N];
int lazy[N];
int ll,rr;
int n,k,m;
void build(int no,int l,int r)
{
	L[no]=l;R[no]=r;
	if(l==r) return;getmid;
	build(lc,l,mid);build(rc,mid+1,r);
	return;
}
void add(int no,int ll,int rr,int hh)
{
	if(L[no]==ll&&R[no]==rr){lazy[no]+=hh;return;}
	getmid;if(ll>mid) {add(rc,ll,rr,hh);return;}
	else if(mid>=rr){add(lc,ll,rr,hh);return;}
	add(lc,ll,mid,hh);add(rc,mid+1,rr,hh);return;
}
void dfs(int no)
{
	S[no]+=lazy[no];
	if(L[no]==R[no])
	{
		if(S[no]>=k)A[L[no]]=1;
		return;
	}
	lazy[lc]+=lazy[no];lazy[rc]+=lazy[no];
	dfs(lc);dfs(rc);
	return;
}
int lowbit(int x)
{
	return (x&(-x));
}
void increase(int x)
{
	for(int i=x;i<=200000;i+=lowbit(i))hh[i]++;
}
int sum(int x)
{
	int res=0;
	for(int i=x;i;i-=lowbit(i))
	res+=hh[i];
	return res;
}
int main()
{
	r(n);r(k);r(m);
	build(1,1,200000);
	for(int i=1;i<=n;i++)
	{
		r(ll);r(rr);add(1,ll,rr,1);
	}
	dfs(1);
	for(int i=1;i<=200000;i++)
	if(A[i]) 
	{
//		cout<<i<<endl;
		increase(i);
	}
	while(m--)
	{
		r(ll);r(rr);
		if(rr>=ll)
		printf("%d\n",sum(rr)-sum(ll-1));
		else
		puts("0");
	}
}