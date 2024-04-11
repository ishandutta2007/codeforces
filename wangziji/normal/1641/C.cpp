#include <bits/stdc++.h>
#define int long long
using namespace std;
int t[200005],fa[200005],ans[200005],lg[200005];
struct query
{
	int op,l,r,x;
}b[200005];
inline int ff(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=ff(fa[x]);
}
inline void cov(int l,int r,int x)
{
	for(int i=ff(l);i<=r;i=ff(i))
	{
		t[i]=x;
		fa[ff(i)]=i+1;
	}
}
struct stree
{
	int l,r,x,pos;
}tr[600005];
inline void build(int now,int l,int r)
{
	tr[now].l=l,tr[now].r=r;
	if(l==r)
	{
		tr[now].x=t[l],tr[now].pos=l;
		return ;
	}
	int mid=(l+r)/2;
	build(now*2,l,mid),build(now*2+1,mid+1,r);
	tr[now].x=max(tr[now*2].x,tr[now*2+1].x);
	if(tr[now*2].x==tr[now*2+1].x) tr[now].pos=0;
	else if(tr[now].x==tr[now*2].x) tr[now].pos=tr[now*2].pos;
	else tr[now].pos=tr[now*2+1].pos;
//	cout << tr[now].l << " " << tr[now].r << " " << tr[now].pos << "*\n";
//	cout << tr[now*2].x<< " " << tr[now*2+1].x<< "\n";
}
inline pair<int,int> query(int now,int l,int r)
{
	if(tr[now].l==l&&tr[now].r==r) return {tr[now].x,tr[now].pos};
	if(tr[now*2].r>=r) return query(now*2,l,r);
	if(tr[now*2+1].l<=l) return query(now*2+1,l,r);
	pair <int,int> A=query(now*2,l,tr[now*2].r);
	pair <int,int> B=query(now*2+1,tr[now*2+1].l,r);
	if(A.first==B.first) return {A.first,0};
	if(A.first>B.first) return A;
	return B;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(int i=2;i<=200000;i++) lg[i]=lg[i>>1]+1;
	int n,q;
	cin >> n >> q;
	for(int i=1;i<=n+1;i++) t[i]=q+1,fa[i]=i;
	for(int i=1;i<=q;i++)
	{
		cin >> b[i].op >> b[i].l;
		if(b[i].op==0)
		{
			cin >> b[i].r >> b[i].x;
			if(!b[i].x) cov(b[i].l,b[i].r,i);
		}
	}
	build(1,1,n);
	for(int i=1;i<=n;i++) ans[i]=q+1;
	for(int i=1;i<=q;i++)
	{
		if(b[i].op==0&&b[i].x==1)
		{
			int p=query(1,b[i].l,b[i].r).second;
			if(!p) continue;
			int qwq=i;
			if(p!=b[i].l) qwq=max(qwq,query(1,b[i].l,p-1).first);
			if(p!=b[i].r) qwq=max(qwq,query(1,p+1,b[i].r).first);
			ans[p]=min(ans[p],max(i,qwq));
		}
	}
	for(int i=1;i<=q;i++)
	{
		if(b[i].op==1)
		{
			if(i<min(ans[b[i].l],t[b[i].l]))
			{
				cout << "N/A\n";
			}
			else if(i>=t[b[i].l])
			{
				cout << "NO\n";
			}
			else cout << "YES\n";
		}
	}
	return 0;
}
/*
2 6
0 1 2 1
1 1
1 2
0 1 1 0
1 1
1 2
*/