#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
il void test(){
	int n;
	scanf("%d",&n);
	ll x=1;
	for(int i=1,y; i<=n; ++i){
		scanf("%d",&y);
		x=x*(i+1)/__gcd((int)x,i+1);
		if(!(y%x)){
			puts("NO");
			for(; ++i<=n; scanf("%*d"));
			return;
		}
		if(x>1000000000)
			for(; ++i<=n; scanf("%*d"));
	}
	puts("YES");
} 
int main(){
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}