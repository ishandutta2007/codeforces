#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#define ll long long
using namespace std;
struct Point
{
	ll x,y;
	Point(ll xx=0,ll yy=0){x=xx,y=yy;}
	Point operator-(Point p){return Point(x-p.x,y-p.y);}
	int quad()
	{
		if(x==0&&y==0)return 0;
		if(x>0&&y>=0)return 1;
		if(x<=0&&y>0)return 2;
		if(x<0&&y<=0)return 3;
		return 4;
	}
	ll det(Point p)
	{
		return x*p.y-y*p.x;
	}
	ll abs2()
	{
		return x*x+y*y;
	}
};
Point p[500005];
struct Edge
{
	int to;
	int nxt;
	ll len;
}e[1000005];
int n,m,k,edgenum,head[500005],size[500005],d[500005],now[500005];
double pre[500005],suf[500005],sum[500005];
vector<ll>v[500005];
vector<double>f[500005];
priority_queue<pair<double,int> >q;
bool cmp(Point a,Point b)
{
	return a.quad()<b.quad()||(a.quad()==b.quad()&&a.det(b)>0)||
		(a.quad()==b.quad()&&a.det(b)==0&&a.abs2()<b.abs2());
}
void add(int u,int v,ll l)
{
	e[++edgenum].len=l;
	e[edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%lld%lld",&p[i].x,&p[i].y);
	sort(p+1,p+n+1,cmp);
	for(int i=2;i<=n;i++)
	{
		if(p[i].quad()==p[i-1].quad()&&p[i].det(p[i-1])==0)v[m].push_back((p[i]-p[i-1]).abs2());
		else v[++m].push_back(p[i].abs2());
	}
	for(int i=1;i<=m;i++)
	{
		double cur=0;
		int N=(int)v[i].size();
		for(int j=0;j<N;j++)
		{
			cur+=sqrt(v[i][j]);
			f[i].push_back(cur*(N-j)*(k-(N-j)));
		}
		cur=0;
		for(int j=N-1;j>=0;j--)
		{
			f[i][j]+=cur;
			cur+=sqrt(v[i][j])*(N-j)*(k-(N-j));
		}
		now[i]=N;
		q.push(make_pair(f[i][N-1],i));
	}
	double ans=0;
	for(int i=1;i<=min(k,n-1);i++)
	{
		ans+=q.top().first;
		int node=q.top().second;
		q.pop();
		now[node]--;
		if(now[node])q.push(make_pair(f[node][now[node]-1]-f[node][now[node]],node));
	}
//	printf("%lf\n",ans);
	int x=1;
	for(int i=1;i<=m;i++)
	{
		if(v[i].size()>v[x].size())
		  x=i;
	}
	double ans2=0;
	for(int i=1;i<=m;i++)
		if(i!=x)ans2+=f[i][0];
	m=(int)v[x].size();
	if(k<n-m)
	{
		printf("%.12lf\n",ans);
		return 0;
	}
	for(int i=0;i<m;i++)sum[i+1]=sqrt(v[x][i]);
	for(int i=1;i<=m;i++)pre[i]=pre[i-1]+sum[i]*(i-1+(n-m))*(k-(i-1+n-m));
	for(int i=m-1;i>=0;i--)suf[i]=suf[i+1]+sum[i+1]*(m-i)*(k-(m-i));
	for(int i=1;i<=m;i++)sum[i]+=sum[i-1];
	double res=0;
	for(int i=0;i+n-k+1<=m;i++)res=max(res,pre[i]+suf[i+n-k+1]+(sum[i+n-k+1]-sum[i])*(m-(i+n-k+1)+1)*(k-(m-(i+n-k+1)+1)));
//	printf("%lf\n",res+ans2);
	printf("%.12lf\n",max(ans,res+ans2));
	return 0;
}