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

int can[maxn+5];

int main()
{
	int m,a,b; scanf("%d%d%d",&m,&a,&b);
	memset(can,63,sizeof can);
	can[0]=0;
	int cnt=1,now=0;
	int g=__gcd(a,b);
	rep(i,1,a+b)
	{
		while(cnt<a/g)
		{
			if(now+a<=i) now+=(i-now)/a*a;
			if(now>=b)
			{
				now-=b;
				can[now%a]=i;
				cnt++;
			}
			else break;
		}
	}
	assert(cnt==a/g);
	ll ans=1ll*(m+1+m+1-m/g*g)*(m/g+1)/2;
	//printf("??? %I64d\n",ans);
	rep(i,1,min(a+b,m)) if(i%g==0 && can[i%a]>i) ans-=min(can[i%a],m+1)-i;
	printf("%I64d\n",ans);
	return 0;
}