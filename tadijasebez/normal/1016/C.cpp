#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
ll max(ll a, ll b){ return a>b?a:b;}
ll min(ll a, ll b){ return a>b?b:a;}
const int N=300050;
ll w[N][2];
int a[N][2],id1[N][2],id2[N][2];
ll b[N][2],c[N][2],sum[N];
int main()
{
	int n,i,j;
	scanf("%i",&n);
	for(j=0;j<2;j++) for(i=1;i<=n;i++) scanf("%i",&a[i][j]);
	for(i=1;i<=n;i++) b[i][0]=(ll)a[i][0]*(i-1),b[i][0]+=b[i-1][0],id1[i][0]=i-1;
	b[n+1][1]=b[n][0];
	for(i=n;i>=1;i--) b[i][1]=(ll)a[i][1]*(n+n-i),b[i][1]+=b[i+1][1],id1[i][1]=n+n-i;
	for(i=1;i<=n;i++) c[i][1]=(ll)a[i][1]*(i-1),c[i][1]+=c[i-1][1],id2[i][1]=i-1;
	c[n+1][0]=c[n][1];
	for(i=n;i>=1;i--) c[i][0]=(ll)a[i][0]*(n+n-i),c[i][0]+=c[i+1][0],id2[i][0]=n+n-i;//printf("\n");
	for(i=n;i>=1;i--) sum[i]=sum[i+1]+a[i][0]+a[i][1];
	for(i=1;i<=n;i++) w[i][0]=b[i][1]-b[i-1][0]-(ll)id1[i][0]*sum[i];
	for(i=1;i<=n;i++) w[i][1]=c[i][0]-c[i-1][1]-(ll)id2[i][1]*sum[i];

	//for(i=1;i<=n;i++) printf("%lld ",a[i][0]);printf("\n");
	//for(i=1;i<=n;i++) printf("%lld ",a[i][1]);printf("\n");

	//for(i=1;i<=n;i++) printf("%lld ",b[i][0]);printf("\n");
	//for(i=1;i<=n;i++) printf("%lld ",b[i][1]);printf("\n");
	
	//for(i=1;i<=n;i++) printf("%lld ",c[i][0]);printf("\n");
	//for(i=1;i<=n;i++) printf("%lld ",c[i][1]);printf("\n");

	//for(i=1;i<=n;i++) printf("%lld ",w[i][0]);printf("\n");
	//for(i=1;i<=n;i++) printf("%lld ",w[i][1]);printf("\n");

	ll sol=w[1][0],ans=0;
	int t=0;
	for(i=1;i<=n;i++)
	{
		if(i&1)
		{
			ans+=(ll)a[i][0]*t;
			t++;
			ans+=(ll)a[i][1]*t;
			t++;
			sol=max(sol,ans+w[i+1][1]+(ll)t*sum[i+1]);
		}
		else
		{
			ans+=(ll)a[i][1]*t;
			t++;
			ans+=(ll)a[i][0]*t;
			t++;
			sol=max(sol,ans+w[i+1][0]+(ll)t*sum[i+1]);
		}
	}
	printf("%lld\n",sol);
	return 0;
}