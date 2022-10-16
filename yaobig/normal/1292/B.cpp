#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

ll x[100],y[100];
ll d[100],s[100];

ll caldis(ll x1,ll y1,ll x2,ll y2)
{
	return abs(x1-x2)+abs(y1-y2);
}

int N;
int solve(int st,ll t)
{
	int ans=0;
	rep(i,1,st) rep(j,st,N) if((s[st]-s[i])*2+(s[j]-s[st])<=t) ans=max(ans,j-i+1);
	rep(i,1,st) rep(j,st,N) if((s[st]-s[i])+(s[j]-s[st])*2<=t) ans=max(ans,j-i+1);
	return ans;
}

int main()
{
	ll x0,y0,ax,ay,bx,by,xs,ys,t;
	scanf("%I64d%I64d%I64d%I64d%I64d%I64d",&x0,&y0,&ax,&ay,&bx,&by);
	scanf("%I64d%I64d%I64d",&xs,&ys,&t);
	
	while(x0<=2e16+5 && y0<=2e16+5)
	{
		N++;
		x[N]=x0; y[N]=y0;
		x0=ax*x0+bx;
		y0=ay*y0+by;
	}
	rep(i,2,N) d[i]=caldis(x[i-1],y[i-1],x[i],y[i]);
	rep(i,2,N) s[i]=s[i-1]+d[i];
	int ans=0;
	rep(i,1,N) 
	{
		ll dis=caldis(xs,ys,x[i],y[i]);
		if(dis<=t) ans=max(ans,solve(i,t-dis));
	}
	printf("%d\n",ans);
	return 0;
}