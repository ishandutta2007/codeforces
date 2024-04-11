#include <bits/stdc++.h>
#define int long long
using namespace std;
int cnt[200100],a[200005];
const int N=200050;
struct stree
{
	int a[200100];
	struct node
	{
		int l,r,sum,cov;
	}t[1100005];
	void build(int now,int l,int r)
	{
		t[now]={l,r,0,-1};
		if(l==r)
		{
			t[now].sum=a[l];
			return ;
		}
		int mid=(l+r)>>1;
		build(now*2,l,mid),build(now*2+1,mid+1,r);
		t[now].sum=t[now*2].sum+t[now*2+1].sum;
	}
	void give(int now,int x)
	{
		t[now].cov=x,t[now].sum=(t[now].r-t[now].l+1)*x;
	}
	void pd(int now)
	{
		if(t[now].cov==-1) return ;
		give(now*2,t[now].cov),give(now*2+1,t[now].cov);
		t[now].cov=-1;
	}
	void cov(int now,int l,int r,int x)
	{
		if(t[now].l==l&&t[now].r==r)
		{
			give(now,x);
			return ;
		}
		pd(now);
		if(t[now*2].r>=r) cov(now*2,l,r,x);
		else if(t[now*2+1].l<=l) cov(now*2+1,l,r,x);
		else cov(now*2,l,t[now*2].r,x),cov(now*2+1,t[now*2+1].l,r,x);
		t[now].sum=t[now*2].sum+t[now*2+1].sum;
	}
	int find(int now)
	{
		if(t[now].l==t[now].r)
		{
			if(t[now].sum) return t[now].l;
			return t[now].l-1;
		}
		pd(now);
		if(t[now*2+1].sum) return find(now*2+1);
		return find(now*2);
	}
	int nxt1(int now,int p)
	{
		if(t[now].l==t[now].r)
		{
			if(!t[now].sum) return N-1;
			return t[now].l;
		}
		pd(now);
		if(t[now*2].r<p||t[now*2].sum==0) return nxt1(now*2+1,p);
		int x=nxt1(now*2,p);
		if(x>=p&&x<=t[now*2].r) return x;
		return nxt1(now*2+1,p);
	}
	int nxt0(int now,int p)
	{
		if(t[now].l==t[now].r)
		{
			if(t[now].sum) return N-1;
			return t[now].l;
		}
		pd(now);
		if(t[now*2].r<p||t[now*2].sum==(t[now*2].r-t[now*2].l+1)) return nxt0(now*2+1,p);
		int x=nxt0(now*2,p);
		if(x>=p&&x<=t[now*2].r) return x;
		return nxt0(now*2+1,p);
	}
}T; 
void sub(int p)
{
	int pos=T.nxt1(1,p);
	if(pos>p) T.cov(1,p,pos-1,1);
	T.cov(1,pos,pos,0);
}
void add(int p)
{
	int pos=T.nxt0(1,p);
	if(pos>p) T.cov(1,p,pos-1,0);
	T.cov(1,pos,pos,1);
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,q;
	cin >> n >> q;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		++cnt[a[i]];
	}
	for(int i=0;i<=N;i++)
	{
		cnt[i+1]+=cnt[i]/2;
		cnt[i]&=1;
	}
	for(int i=1;i<=N;i++) T.a[i]=cnt[i];
	T.build(1,1,N);
	while(q--)
	{
		int p,x;
		cin >> p >> x;
		sub(a[p]);
		add(x);
		a[p]=x;
		cout << T.find(1) << "\n";
	}
	return 0;
}