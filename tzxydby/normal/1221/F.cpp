#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000005;
struct ans
{
	int p,x,y;
	bool operator<(const ans k)const
	{
		return p<k.p;
	}
}r,h;
int n,m,x[N],y[N],c[N],tag[N<<2];
vector<int>v;
vector<pair<int,int>>q[N];
pair<int,int> tr[N<<2];
void pushdown(int k)
{
	if(tag[k])
	{
		tr[k<<1].first+=tag[k];
		tag[k<<1]+=tag[k];
		tr[k<<1|1].first+=tag[k];
		tag[k<<1|1]+=tag[k];
		tag[k]=0;
	}
}
void build(int k,int l,int r)
{
	if(l==r)
	{
		tr[k]=make_pair(v[l-1],l);
		return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	tr[k]=max(tr[k<<1],tr[k<<1|1]);
}
void update(int k,int l,int r,int a,int b,int v)
{
	if(l==a&&r==b)
	{
		tr[k].first+=v;
		tag[k]+=v;
		return;
	}
	pushdown(k);
	int mid=l+r>>1;
	if(b<=mid) update(k<<1,l,mid,a,b,v);
	else if(a>mid) update(k<<1|1,mid+1,r,a,b,v);
	else update(k<<1,l,mid,a,mid,v),update(k<<1|1,mid+1,r,mid+1,b,v);
	tr[k]=max(tr[k<<1],tr[k<<1|1]);
}
pair<int,int> query(int k,int l,int r,int a,int b)
{
	if(l==a&&r==b)
		return tr[k];
	pushdown(k);
	int mid=l+r>>1;
	if(b<=mid) return query(k<<1,l,mid,a,b);
	else if(a>mid) return query(k<<1|1,mid+1,r,a,b);
	else return max(query(k<<1,l,mid,a,mid),query(k<<1|1,mid+1,r,mid+1,b));
}
signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i]>>c[i];
		if(x[i]>y[i])
			swap(x[i],y[i]);
		v.push_back(x[i]);
		v.push_back(y[i]);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	m=v.size();
	for(int i=1;i<=n;i++)
	{
		x[i]=lower_bound(v.begin(),v.end(),x[i])-v.begin()+1;
		y[i]=lower_bound(v.begin(),v.end(),y[i])-v.begin()+1;
		q[y[i]].emplace_back(x[i],c[i]);
	}
	build(1,1,m);
	r={0,2000000000,2000000000};
	for(int y=1;y<=m;y++)
	{
		for(auto it:q[y])
			update(1,1,m,1,it.first,it.second);
		pair<int,int> d=query(1,1,m,1,y);
		int c=d.first,x=d.second;
		h={c-v[y-1],v[x-1],v[y-1]};
		if(r<h)
			r=h;
	}
	cout<<r.p<<endl<<r.x<<' '<<r.x<<' '<<r.y<<' '<<r.y<<endl;
	return 0;
}