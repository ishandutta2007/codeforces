#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
#define max_k 100000
int p[max_k+1];
int find(int&x){
	return p[x]?(x=find(p[x])):x;
}
il void test(){
	int n,k;
	scanf("%d%d",&n,&k);
	memset(p+1,0,n<<2);
	int ans=0;
	for(int i=1,u,v; i<=k; ++i){
		scanf("%d%d",&u,&v);
		find(u);
		find(v);
		if(u!=v){
			p[u]=v,++ans;
		}
	}
	printf("%d\n",k-ans);
}
int main(){
	test();
//	int t;
//	for(scanf("%d",&t); t; test(),--t);
	return 0;
}