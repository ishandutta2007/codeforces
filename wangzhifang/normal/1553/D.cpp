#include <cstdio>
#include <cstring>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
char s[100002],t[100002];
il void test(){
	scanf("\n%s\n%s",s+1,t+1);
	int n=strlen(s+1),m=strlen(t+1);
	while(n>0)
		if(s[n]==t[m]){
			--n,--m;
			if(!m){
				puts("YES");
				return;
			}
		}
		else
			n-=2;
	puts("NO");
}
int main(){
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}