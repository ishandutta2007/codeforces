#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define cs const
#define il __inline__ __attribute__((always_inline))
typedef cs int& ci;
typedef long long ll;
constexpr int max_n=15;
int a[max_n+1];
il void test(){
	int n;
	scanf("%d",&n);
	int cnt=0,ans=0;
	for(int x,i=n; i; --i){
		scanf("%d",&x);
		while(!(x&1))
			x>>=1,++cnt;
		ans+=a[i]=x;
	}
	printf("%lld\n",(*max_element(a+1,a+n+1))*((1ull<<cnt)-1)+ans);
}
int main(){
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}