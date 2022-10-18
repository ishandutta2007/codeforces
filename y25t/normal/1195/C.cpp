#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long
#define N 100005

ll n,a[N][2];

ll dp[N][2],mx[2];

int main(){
	scanf("%I64d",&n);
	for(ll k=0;k<2;k++)
		for(ll i=1;i<=n;i++)
			scanf("%I64d",&a[i][k]);
	for(ll i=1;i<=n;i++){
		ll tmp[2]={mx[0],mx[1]};
		for(ll k=0;k<2;k++){
			dp[i][k]=tmp[k^1]+a[i][k];
			mx[k]=max(mx[k],dp[i][k]);
		}
	}
	printf("%I64d",max(mx[0],mx[1]));
}