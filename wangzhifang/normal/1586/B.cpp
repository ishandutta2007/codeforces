#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
#define max_n 100000
bool vis[max_n+1];
il void test(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1,x; i<=m; vis[x]=1,++i)
		scanf("%*d%d%*d",&x);
	int pos=0;
	for(int i=1; i<=n; ++i)
		if(!vis[i])
			pos=i;
		else
			vis[i]=0;
	for(int i=1; i<pos; ++i)
		printf("%d %d\n",i,pos);
	for(int i=n; i>pos; --i)
		printf("%d %d\n",i,pos);
}
int main(){
//	test();
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}