#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,r,c,p[10],rp[10],pt[10];
pair<int,int>a[N],b[N];
vector<int>vx,vy;
int lc[N<<5],rc[N<<5],sum[N<<5],cnt,rt[N],en[N];
void build(int &k,int l,int r)
{
	k=++cnt;
	if(l==r)
		return;
	int mid=(l+r)>>1;
	build(lc[k],l,mid);
	build(rc[k],mid+1,r);
}
int modify(int k,int l,int r,int p)
{
	int t=++cnt;
	lc[t]=lc[k],rc[t]=rc[k],sum[t]=sum[k]+1;
	if(l==r)
		return t;
	int mid=(l+r)>>1;
	if(p<=mid) lc[t]=modify(lc[t],l,mid,p);
	else rc[t]=modify(rc[t],mid+1,r,p);
	return t;
}
int query(int k,int l,int r,int a,int b)
{
	if(l==a&&r==b)
		return sum[k];
	int mid=(l+r)>>1;
	if(b<=mid) return query(lc[k],l,mid,a,b);
	else if(a>mid) return query(rc[k],mid+1,r,a,b);
	else return query(lc[k],l,mid,a,mid)+query(rc[k],mid+1,r,mid+1,b);
}
bool cmp(pair<int,int> x,pair<int,int> y){return x.second==y.second?x.first<y.first:x.second<y.second;}
void solve()
{
	static int cnt=0;
	int x[4]={0,a[p[1]+p[2]+p[3]].first,a[p[1]+p[2]+p[3]+p[4]+p[5]+p[6]].first,r};
	int y[4]={0,b[p[1]+p[4]+p[7]].second,b[p[1]+p[2]+p[4]+p[5]+p[7]+p[8]].second,c};
	for(int i=1;i<=9;i++)
	{
		int kx=(i-1)/3+1,ky=(i-1)%3+1;
		if(query(rt[en[x[kx]]],1,c,y[ky-1]+1,y[ky])-query(rt[en[x[kx-1]]],1,c,y[ky-1]+1,y[ky])!=p[i])
			return;
	}
	printf("%.6f %.6f\n%.6f %.6f\n",0.5+vx[x[1]-1],0.5+vx[x[2]-1],0.5+vy[y[1]-1],0.5+vy[y[2]-1]);
	exit(0);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].first,&a[i].second);
		vx.push_back(a[i].first);
		vy.push_back(a[i].second);
	}
	sort(vx.begin(),vx.end());
	vx.erase(unique(vx.begin(),vx.end()),vx.end());
	r=vx.size();
	sort(vy.begin(),vy.end());
	vy.erase(unique(vy.begin(),vy.end()),vy.end());
	c=vy.size();	
	for(int i=1;i<=n;i++)
		a[i]=make_pair(lower_bound(vx.begin(),vx.end(),a[i].first)-vx.begin()+1,
			           lower_bound(vy.begin(),vy.end(),a[i].second)-vy.begin()+1),
		b[i]=a[i];
	sort(a+1,a+n+1);
	sort(b+1,b+n+1,cmp);
	build(rt[0],1,c);
	for(int i=1;i<=n;i++)
		rt[i]=modify(rt[i-1],1,c,a[i].second),en[a[i].first]=i;
	for(int i=1;i<=9;i++)
		scanf("%d",&rp[i]),pt[i]=i;
	do
	{
		for(int i=1;i<=9;i++)
			p[i]=rp[pt[i]];
		solve();
	}while(next_permutation(pt+1,pt+10));
	puts("-1");
	return 0;
}