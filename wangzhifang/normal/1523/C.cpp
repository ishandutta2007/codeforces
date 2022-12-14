#include <cstdio>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
#define max_n 1000
int stk[max_n+1];
il void test(){
	int n;
	scanf("%d",&n);
	for(int tp=0,x; n; --n){
		scanf("%d",&x);
		if(x==1)
			stk[++tp]=1;
		else{
			for(int v=x-1; stk[tp]!=v; --tp);
			++stk[tp];
		}
		for(int i=1; i<tp; ++i)
			printf("%d.",stk[i]);
		printf("%d\n",stk[tp]);
	}
}
int main(){
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}