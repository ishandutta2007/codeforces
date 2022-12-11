#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef long long ll;
#define max_n 5000
int t,n,tag[max_n+1],s[max_n+1];
ll f[max_n+1];
il void test(){
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d",tag+i);
	for(int i=1; i<=n; ++i)
		scanf("%d",s+i);
	memset(f+1,0,n<<3);
	for(int i=1; i<=n; ++i)
		for(int j=i; --j; ){
			if(tag[i]==tag[j])
				continue;
			ll fi=f[i],fj=f[j],tmp=abs(s[i]-s[j]);
			f[i]=max(f[i],fj+tmp),f[j]=max(f[j],fi+tmp);
		}
	printf("%lld\n",*max_element(f+1,f+n+1));
}
int main(){
	int t;
	for(scanf("%d",&t); t; test(),--t);
    return 0;
}