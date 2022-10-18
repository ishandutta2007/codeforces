#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define fir first
#define sec second
#define mod 998244353
#define ll long long
#define eps (1e-13)
#define inf 1e18
#define INF 0x3f3f3f3f3f3f3f3f
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
inline int min(int x,int y,int z){return min(x,min(y,z));}
inline int max(int x,int y,int z){return max(x,max(y,z));}
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
#define N 25005
int x[N],y[N],dx[N],dy[N],v[N],n;
double k[N],b[N];
double solve(int i,int j)
{
	double tx=(b[i]-b[j])/(k[j]-k[i]);
	double ty=tx*k[i]+b[i];
	if((tx-x[i])*dx[i]<-eps) return inf;
	if((tx-x[j])*dx[j]<-eps) return inf;
	double A=sqrt((x[i]-tx)*(x[i]-tx)+(y[i]-ty)*(y[i]-ty))/v[i];
	double B=sqrt((x[j]-tx)*(x[j]-tx)+(y[j]-ty)*(y[j]-ty))/v[j];
	// assert(min(A,B)>=0);
	return max(A,B);
}
double solve2(int i,int j)
{
	// printf("++ %d %d %d\n",i,j,(x[i]-x[j])*dx[j]);
	if((x[j]-x[i])*dx[i]<0&&(x[i]-x[j])*dx[j]<0) return inf;
	double d=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
	if((x[j]-x[i])*dx[i]<-eps) return d/v[j];
	if((x[i]-x[j])*dx[j]<-eps) return d/v[i];
	return d/(v[i]+v[j]);
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++) x[i]=read(),y[i]=read(),dx[i]=read(),dy[i]=read(),v[i]=read();
	for(int i=1;i<=n;i++)
	{
		int t=__gcd(dx[i],dy[i]);
		if(t<0) t=-t;
		dx[i]/=t,dy[i]/=t;
	}
	for(int i=1;i<=n;i++)
	{
		k[i]=(double)dy[i]/dx[i];
		b[i]=y[i]-x[i]*k[i];
	}
	// for(int i=1;i<=n;i++) printf("%.3lf %.3lf\n",k[i],b[i]);
	double ans=inf;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(abs(k[i]-k[j])<=eps)
			{
				if(abs(b[i]-b[j])<=eps)
				{
					// printf("-- %d %d %.7lf\n",i,j,solve2(i,j));
					ans=min(ans,solve2(i,j));
				}
			}
			else ans=min(ans,solve(i,j));
		}
	}
	if(ans==inf) cout<<"No show :(";
	else printf("%.6lf\n",ans);
	return 0;
}