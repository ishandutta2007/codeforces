#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
const int N=6005,mod=1000000007;
int n,k,l,ln,lm,mn[N<<2],cm[N<<2],sz[N<<2],ans[N<<2],tag[N<<2],b[N],ls[N],sum;
struct node
{
	int x,y,c;
	bool operator<(const node k)const
	{
		return x==k.x?y<k.y:x<k.x;
	}
}a[N];
vector<int>vx,vy,xd[N],yd[N];
multiset<int>s[N],st;
void pushup(int k)
{
	ans[k]=(ans[k<<1]+ans[k<<1|1])%mod;
	if(mn[k<<1]<mn[k<<1|1])
	{
		mn[k]=mn[k<<1];
		sz[k]=sz[k<<1]; 
		cm[k]=min(cm[k<<1],mn[k<<1|1]);
	}
	else if(mn[k<<1]>mn[k<<1|1])
	{
		mn[k]=mn[k<<1|1];
		sz[k]=sz[k<<1|1];
		cm[k]=min(mn[k<<1],cm[k<<1|1]);
	}
	else
	{
		mn[k]=mn[k<<1];
		sz[k]=sz[k<<1]+sz[k<<1|1];
		cm[k]=min(cm[k<<1],cm[k<<1|1]);	
	}
}
void change(int k,int v)
{
	if(v<=mn[k])
		return;
	if(v<cm[k])
	{
		ans[k]=(ans[k]+1ll*(v-mn[k])*sz[k]%mod)%mod;
		tag[k]=max(tag[k],v);
		mn[k]=v;
		return;
	}
	change(k<<1,v);
	change(k<<1|1,v);
	pushup(k);
}
void pushdown(int k)
{
	change(k<<1,tag[k]);
	change(k<<1|1,tag[k]);
}
void build(int k,int l,int r)
{
	tag[k]=0;
	if(l==r)
	{
		mn[k]=vy[b[l]];
		cm[k]=2e9;
		sz[k]=(vy[l+1]-vy[l])%mod;
		ans[k]=1ll*mn[k]*sz[k]%mod;
		return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	pushup(k);
}
void update(int k,int l,int r,int a,int b,int v)
{
	if(l==a&&r==b)
	{
		change(k,v);
		return;
	}
	pushdown(k);
	int mid=l+r>>1;
	if(b<=mid) update(k<<1,l,mid,a,b,v);
	else if(a>mid) update(k<<1|1,mid+1,r,a,b,v);
	else update(k<<1,l,mid,a,mid,v),update(k<<1|1,mid+1,r,mid+1,b,v);
	pushup(k);
}
void del(int p)
{
	int c=a[p].c,y=a[p].y;
	s[c].erase(s[c].find(y));
	if(s[c].count(y))
		return;
	auto it=s[c].lower_bound(y);
	int ri=*it,le=*(--it)+1;
	update(1,1,lm,le,y,vy[ri]);
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>k>>l;
	vx.push_back(l+1),vx.push_back(1),vx.push_back(0);
	vy.push_back(l+1),vy.push_back(1),vy.push_back(0);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y>>a[i].c;
		a[i].x++;
		a[i].y++;
		vx.push_back(a[i].x);
		vx.push_back(a[i].x+1);
		vy.push_back(a[i].y);
		vy.push_back(a[i].y+1);
	}
	sort(vx.begin(),vx.end());
	vx.erase(unique(vx.begin(),vx.end()),vx.end());
	sort(vy.begin(),vy.end());
	vy.erase(unique(vy.begin(),vy.end()),vy.end());
	ln=vx.size()-2,lm=vy.size()-2;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		a[i].x=lower_bound(vx.begin(),vx.end(),a[i].x)-vx.begin();
		a[i].y=lower_bound(vy.begin(),vy.end(),a[i].y)-vy.begin();
		xd[a[i].x].push_back(i);
		yd[a[i].y].push_back(i);
	}
	for(int i=1;i<=ln;i++)
	{
		st.clear();
		for(int j=1;j<=k;j++)
		{
			s[j].clear();
			s[j].insert(0);
			s[j].insert(lm+1);
			ls[j]=lm+1;
			st.insert(ls[j]);
		}
		for(int j=lm;j>=1;j--)
		{
			for(auto p:yd[j])
			{
				if(a[p].x>i)
					continue;
				int c=a[p].c;
				s[c].insert(a[p].y);
				if(ls[c]!=j)
				{
					st.erase(st.find(ls[c]));
					ls[c]=j;
					st.insert(ls[c]);
				}
			}
			b[j]=*(--st.end());
		}
		build(1,1,lm);
		for(int j=1;j<=i;j++)
		{
			sum=(sum+(1ll*l*(l+1)%mod+mod-ans[1]%mod)%mod*(vx[i+1]-vx[i])%mod*(vx[j+1]-vx[j])%mod)%mod;
			for(auto p:xd[j])
				del(p);
		}
	}
	cout<<sum<<endl;
	return 0;
}