#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
#define max_t 1000000
int a[max_t+1],b[max_t+1];
il bool check(ci n,ci m,ci x,ci y){
//	printf("check %d %d %d %d\n",n,m,x,y);
	if(y<=0||x<=0||y>m||x>n)
		return 0;
	memset(a,0,(n*m+1)<<2);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			++a[abs(i-x)+abs(j-y)];
//	for(int i=1; i<=n*m; ++i)
//		printf("%d: %d\n",i,a[i]);
	if(!memcmp(a+1,b+1,(n*m)<<2)){
		printf("%d %d\n%d %d\n",n,m,x,y);
		return 1;
	}
	return 0;
}
il void test(){
	int t,mx=0;
	scanf("%d",&t);
	for(int i=1,x; i<=t; ++i,++b[x],x>mx&&(mx=x))
		scanf("%d",&x);
	if(!b[0]){
		puts("-1");
		return;
	}
	int p=mx+1;
	for(int i=0; i<=mx; ++i)
		if(b[i]<4*i){
			p=i;
			break;
		}
	for(int n=1; n*n<=t; ++n)
		if(!(t%n)){
			int m=t/n;
			if(check(n,m,n-p+1,mx-n+p+1))
				return;
			if(check(m,n,m-p+1,mx-m+p+1))
				return;
		}
	puts("-1");
}
int main(){
	test();
//	int t;
//	for(scanf("%d",&t); t; test(),--t);
	return 0;
}