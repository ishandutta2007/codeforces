#include <bits/stdc++.h>
using namespace std;
const int Maxn=400005;
long long m,a,b,c,x,y,now,maxi,ans,mini[Maxn];
bool vis[Maxn];
long long gcd(long long x,long long y)
{
	return x==0?y:gcd(y%x,x);
}
void exgcd(long long a,long long b,long long &X,long long &Y)
{
    if(b==0)
        X=1,Y=0;
    else
    {
        exgcd(b,a%b,X,Y);
        long long tmp=X;
        X=Y;
        Y=tmp-a/b*Y;
    }
}
void get_maxi(void)
{
	while(x<=0) x+=b/c,y-=a/c;
	y*=-1;
	while(x+y)
	{
		if(now>=b&&y) now-=b,y--;
		else now+=a,x--;
		maxi=max(maxi,now);
	}
}
void SPFA(void)
{
	queue <int> Qu;
	Qu.push(0);
	memset(mini,0x3f,sizeof(long long[2*maxi+1]));
	mini[0]=0;
	while(!Qu.empty())
	{
		int u=Qu.front();
		vis[u]=false;
		Qu.pop();
		if(u+a<=2*maxi&&max(u+a,mini[u])<mini[u+a])
		{
			mini[u+a]=max(u+a,mini[u]);
			if(!vis[u+a])
				Qu.push(u+a),vis[u+a]=true;
		}
		if(u-b>=0&&mini[u]<mini[u-b])
		{
			mini[u-b]=mini[u];
			if(!vis[u-b])
				Qu.push(u-b),vis[u-b]=true;
		}
	}
}
int main()
{
	scanf("%lld%lld%lld",&m,&a,&b);
	c=gcd(a,b);
	exgcd(a/c,b/c,x,y);
	get_maxi();
	SPFA();
	for(int i=0;i<=maxi;i++)
		ans+=max(0LL,m-mini[i]+1);
	if(m<=maxi)
	{
		printf("%lld",ans);
		return 0;
	}
	long long Begin=maxi+c-maxi%c,End=(m/c)*c,Element=(End-Begin)/c+1;
	ans+=(m+1)*Element-(Begin+End)*Element/2;
	printf("%lld",ans);
	return 0;
}