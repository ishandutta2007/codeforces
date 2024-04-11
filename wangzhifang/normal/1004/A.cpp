#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
#define max_n 100
int a[max_n+1];
il void test(){
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	int ans=2;
	for(int i=1; i<n; ++i)
		if(a[i+1]-a[i]>d*2)
			ans+=2;
		else
			if(a[i+1]-a[i]==d*2)
				++ans;
	printf("%d\n",ans);
}
int main(){
	test();
//	int t;
//	for(scanf("%d",&t); t; test(),--t);
	return 0;
}