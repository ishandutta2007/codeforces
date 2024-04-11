#include <iostream>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
il void test(){
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	printf("%d\n",abs(a-c)+abs(b-d)+int(a!=c&&b!=d)*2);
}
int main(){
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}