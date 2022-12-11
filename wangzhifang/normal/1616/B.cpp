#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define cs const
#define il __inline__ __attribute__((always_inline))
constexpr int max_n=200000;
char str[max_n+1];
il void test(){
	int n;
	scanf("%d\n%s",&n,str+1);
	for(int i=n; i>1; --i)
		if(str[i]>str[i-1])
			n=i-1;
	if(n>1&&str[1]==str[2]){
		str[3]='\0';
		printf("%s\n",str+1);
		return;
	}
	for(int i=1; i<=n; ++i)
		putchar(str[i]);
	for(int i=n; i; --i)
		putchar(str[i]);
	putchar('\n');
}
int main(){
	int t;
	for(scanf("%d",&t); t; test(),--t);
//	test();
	return 0;
}