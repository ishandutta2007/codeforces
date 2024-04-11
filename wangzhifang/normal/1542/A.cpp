#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
il void test(){
	int n,cnt[2]={0,0};
	scanf("%d",&n);
	for(int i=n,x,y; i; --i,++cnt[x&1],++cnt[y&1])
		scanf("%d%d",&x,&y);
	puts(cnt[0]==cnt[1]?"Yes":"No");
}
int main(){
//	test();
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}