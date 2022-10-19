#include<bits/stdc++.h>
using namespace std;
const int N=305;
int n,m,a[N*N],p[N][N],c[N*N];
vector<int>v,vx[N*N],vy[N*N];
long long ans;
struct bit
{
	int b[N],s;
	void init(int _s)
	{
		s=_s;
		for(int i=0;i<=s;i++)
			b[i]=0;
	}
	void add(int x,int v)
	{
		for(int i=x;i<=s;i+=i&(-i))
			b[i]+=v;
	}
	int ask(int x)
	{
		int v=0;
		for(int i=x;i;i-=i&(-i))
			v+=b[i];
		return v;
	}
}b[N];
void sol()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n*m;i++)
	{
		c[i]=0;
		vx[i].clear();
		vy[i].clear();
	}
	for(int i=0;i<=n;i++)
		b[i].init(m);
	v.clear();
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
		v.push_back(a[i]);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=1;i<=n*m;i++)
	{
		a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;
		c[a[i]]++;
	}
	int nx=1,ny=1;
	for(int i=1;i<=n*m;i++)
	{
		for(int j=1;j<=c[i];j++)
		{
			p[nx][ny]=i;
			ny++;
			if(ny>m)
				nx++,ny=1;
		}
	}
	for(int i=n;i>=1;i--)
		for(int j=1;j<=m;j++)
			vx[p[i][j]].push_back(i),vy[p[i][j]].push_back(j);
	ans=0;
	for(int i=1;i<=n*m;i++)
	{
		int x=vx[a[i]].back(),y=vy[a[i]].back();
		vx[a[i]].pop_back(),vy[a[i]].pop_back();
		ans+=b[x].ask(y);
		b[x].add(y,1);
	}
	printf("%lld\n",ans);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();	
	return 0;
}