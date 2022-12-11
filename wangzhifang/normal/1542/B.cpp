#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
il void test(){
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	if(a==1){
		puts((n-1)%b==0?"Yes":"No");
		return;
	}
	for(ll now=1; now<=n; now*=a){
		if(!((n-now)%b)){
			puts("Yes");
			return;
		}
	}
	puts("No");
}
int main(){
//	test();
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}