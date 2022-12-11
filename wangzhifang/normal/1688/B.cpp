#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
constexpr int max_n=200000;
int a[max_n+1];
void test(){
	int n;
	scanf("%d",&n);
	int g=1<<30,cnt=0;
	for(int i=1; i<=n; ++i){
		scanf("%d",a+i);
		cnt+=!(a[i]&1),g=__gcd(g,a[i]);
	}
	printf("%d\n",g==1?cnt:(cnt+__builtin_ctz(g)-1));
}
int main(){
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}