#include <cstdio>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
il void test(){
	int n,x,mx=0,flg=0;
	scanf("%d%d",&n,&x);
	for(int i=1,t; i<=n; ++i){
		scanf("%d",&t);
		if(t==x)
			flg=1;
		if(t>mx)
			mx=t;
	}
	if(flg){
		puts("1");
		return;
	}
	printf("%d\n",x>mx?(x-1)/mx+1:2);
}
int main(){
	int t;
	for(scanf("%d",&t); t; --t,test());
	return 0;
}