#include <cstdio>
using namespace std;
typedef long long ll;
int main(){
	int t;
	for(scanf("%d",&t); t; --t){
		ll a,b,x;
		scanf("%lld%lld%lld",&a,&b,&x);
		if(a>b)
			goto case1;
		goto case2;
		case1:
			if(x>a||!b){
				puts("NO");
				continue;
			}
			if(x%b==a%b){
				puts("YES");
				continue;
			}
			a%=b;
			goto case2;
		case2:
			if(x>b||!a){
				puts("NO");
				continue;
			}
			if(x%a==b%a){
				puts("YES");
				continue;
			}
			b%=a;
			goto case1;
	}
	return 0;
}