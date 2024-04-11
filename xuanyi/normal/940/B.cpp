#include <cstdio>
using namespace std;
typedef long long ll;
int n,k,A,B;
ll ans;
int main(){
	scanf("%d%d%d%d",&n,&k,&A,&B);
	while (n!=1){
		if (n<k){
			ans=ans+1ll*A*(n-1);
			break;
		}
		if (n%k){
			ans=ans+1ll*n%k*A;
			n=n/k*k;
		}
		if (1ll*(n-n/k)*A<B){
			ans=ans+1ll*A*(n-1);
			break;
		}
		else{
			n/=k;
			ans=ans+B;	
		}
	}
	printf("%lld\n",ans);
	return 0;
}