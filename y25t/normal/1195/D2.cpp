#include<cstdio>
#define ll long long
#define P 998244353
#define N 100005

ll p10[15];
inline void prep10(){
	p10[0]=1;
	for(ll i=1;i<=10;i++)
		p10[i]=p10[i-1]*10;
}

ll n,a[N];

ll lg[N],cnt[N],sum[N];

ll ans;

int main(){
	prep10();
	scanf("%I64d",&n);
	for(ll i=1;i<=n;i++){
		scanf("%I64d",&a[i]);
		while(p10[lg[i]]<=a[i])
			lg[i]++;
		cnt[lg[i]]++;
	}
	for(ll i=1;i<=10;i++){
		sum[i]=(sum[i-1]+cnt[i]*p10[i]%P)%P;
		cnt[i]+=cnt[i-1];
	}
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=lg[i];j++){
			ll b=a[i]/p10[j-1]%10;
			ans+=b*p10[j-1]*(2*sum[j-1]%P+(n-cnt[j-1])*p10[j-1]%P*11%P)%P;
			ans%=P;
		}
	printf("%I64d",ans);
}