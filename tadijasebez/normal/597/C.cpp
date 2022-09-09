#include <stdio.h>
#define ll long long
const int N=100050;
ll dp[N][12];
int a[N];
ll BIT[N];
void Init(){ for(int i=0;i<N;i++) BIT[i]=0;}
void Set(int i, ll f){ for(;i<N;i+=i&-i) BIT[i]+=f;}
ll Get(int i){ ll ret=0;for(;i;i-=i&-i) ret+=BIT[i];return ret;}
int main()
{
	int n,k,i,j;
	scanf("%i %i",&n,&k);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),dp[i][0]=1;
	for(j=1;j<=k;j++)
	{
		Init();
		for(i=1;i<=n;i++)
		{
			dp[i][j]=Get(a[i]);
			Set(a[i],dp[i][j-1]);
		}
	}
	ll sol=0;
	for(i=1;i<=n;i++) sol+=dp[i][k];
	printf("%lld\n",sol);
	return 0;
}