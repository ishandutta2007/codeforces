#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
#define max_n 300000
int a[max_n+1],b[max_n+1];
il void test(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1; i<=n; ++i)
		scanf("%d",a+i);
	memcpy(b+1,a+1,n<<2);
	sort(b+1,b+n+1);
	for(int i=1; i<=n; ++i)
		a[i]=lower_bound(b+1,b+n+1,a[i])-b;
	int cnt=1;
	for(int i=2; i<=n; ++i)
		if(a[i]!=a[i-1]+1)
			++cnt;
//	printf("%d\n",cnt);
	puts(cnt<=k?"Yes":"No");
}
int main(){
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}