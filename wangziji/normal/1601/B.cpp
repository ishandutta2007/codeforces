#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[2000005],b[2000005],dis[2000005],q[5000005],lst[2000005],l=2500000,r=2499999,X[2000005];
vector <pair<int,pair<int,int> > > e[2000005];
const int qwq=300005;
struct stree
{
	int l,r;
}t[2000005];
inline void build(int now,int l,int r)
{
	t[now].l=l,t[now].r=r;
	if(l==r)
	{
//		cout << qwq+now << " " << l << "\n";
		e[qwq+now].push_back({b[l],{0,l}});
		return ;
	}
	int mid=(l+r)/2;
	build(now*2,l,mid),build(now*2+1,mid+1,r);
//	cout << now+qwq << " " << now*2+qwq << "\n";
//	cout << now+qwq << " " << now*2+qwq+1 << "\n";
	e[now+qwq].push_back({now*2+qwq,{0,now*2+qwq}}),e[now+qwq].push_back({now*2+1+qwq,{0,now*2+1+qwq}});
}
inline void add(int x,int now,int l,int r)
{
	if(t[now].l==l&&t[now].r==r)
	{
//		cout << x << " " << now+qwq << "\n";
		e[x].push_back({now+qwq,{1,now+qwq}});
		return ;
	}
	if(t[now*2].r>=r) add(x,now*2,l,r);
	else if(t[now*2+1].l<=l) add(x,now*2+1,l,r);
	else add(x,now*2,l,t[now*2].r),add(x,now*2+1,t[now*2+1].l,r);
}
signed main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=1;i<=n;i++)
	{
		cin >> b[i];
		b[i]+=i;
	}
	build(1,0,n);
	for(int i=1;i<=n;i++)
		add(i,1,i-a[i],i);
	for(int i=0;i<=2000000;i++) dis[i]=1e9;
	q[++r]=n,dis[n]=0;
	while(l<=r)
	{
		int x=q[l++];
//		cout << x << " " << lst[x] << "**\n";
		for(auto v:e[x])
		{
			if(dis[v.first]>dis[x]+v.second.first)
			{
				if(v.second.first==1) dis[v.first]=dis[x]+v.second.first,q[++r]=v.first,lst[v.first]=x,X[v.first]=v.second.second;
				else dis[v.first]=dis[x]+v.second.first,q[--l]=v.first,lst[v.first]=x,X[v.first]=v.second.second;
			}
		}
	}
	if(dis[0]>n*2)
	{
		cout << -1;
		return 0;
	}
	cout << dis[0] << "\n";
	int now=0;
	vector <int> v;
	while(now!=n)
	{
		if(now<=n) v.push_back(X[now]);
		now=lst[now];
	}
	reverse(v.begin(),v.end());
	for(auto t:v) cout << t << " ";
	return 0;
}