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
	for(int x,y; n; n-=2){
		scanf("%d%d",&x,&y);
		printf("%d %d ",-y,x);
	}
	putchar('\n');
}
int main(){
//	test();
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}