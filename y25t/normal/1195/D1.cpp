#include<cstdio>
#define ll long long
#define P 998244353

ll n;

ll ans;

int main(){
	scanf("%I64d",&n);
	for(ll i=1;i<=n;i++){
		ll a;
		scanf("%I64d",&a);
		for(ll i=1,tmp=1;i<=10;i++,tmp*=10){
			ll b=a/tmp%10;
			ans+=tmp*tmp%P*b*11*n%P;
			ans%=P;
		}
	}
	printf("%I64d",ans);
}