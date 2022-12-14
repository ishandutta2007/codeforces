#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
char s[500001];
il void test(){
	scanf("%s",s+1);
	int n=strlen(s+1),mn=255;
	for(int i=1; i<=n; ++i){
		s[i]<mn&&(mn=s[i]);
		if(s[i]==mn)
			puts("Mike");
		else
			puts("Ann");
	}
}
int main(){
	test();
//	int t;
//	for(scanf("%d",&t); t; test(),--t);
	return 0;
}