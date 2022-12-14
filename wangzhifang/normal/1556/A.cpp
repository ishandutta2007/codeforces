#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
il void test(){
	int a,b;
	scanf("%d%d",&a,&b);
	if((a^b)&1)
		puts("-1");
	else{
		if(!a&&!b)
			puts("0");
		else
			if(a==b)
				puts("1");
			else
				puts("2");
	}
}
int main(){
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}