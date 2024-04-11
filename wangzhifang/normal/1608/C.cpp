#include <array>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
constexpr int max_n=100000;
array<int,3>a[max_n+1];
int mx[max_n+1];
bool ans[max_n+1];
il void test(){
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i){
		scanf("%d",&a[i][0]);
		a[i][2]=i,ans[i]=0;
	}
	for(int i=1; i<=n; ++i)
		scanf("%d",&a[i][1]);
	sort(a+1,a+n+1);
	int now=mx[1]=a[1][1];
	for(int i=2; i<=n; ++i){
		a[i][1]>now&&(now=a[i][1]);
		mx[i]=now;
	}
	ans[a[n][2]]=1,now=a[n][1];
	for(int i=n; --i; ){
//		printf("%d %d %d\n",a[i][0],a[i][1],a[i][2]);
//		printf("%d %d\n",mx[i],now);
		if(mx[i]>now)
			ans[a[i][2]]=1;
		else
			break;
		a[i][1]<now&&(now=a[i][1]);
	}
	for(int i=1; i<=n; ++i)
		putchar(ans[i]|'0');
	putchar('\n');
}
int main(){
	int t;
	for(scanf("%d",&t); t; test(),--t);
//	test();
	return 0;
}