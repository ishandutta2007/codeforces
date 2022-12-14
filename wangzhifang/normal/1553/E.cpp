#include <cstdio>
#include <cstring>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
#define max_n 300000
int p[max_n],cnt[max_n],ans[4],par[max_n];
int find(int&x){
	return x==par[x]?x:(x=find(par[x]));
}
il bool check(ci n,ci m,ci pos){
//	printf("check %d\n",pos);
	for(int i=0; i<n; ++i)
		par[i]=i;
	int ans=0;
	for(int i=0; i<n; ++i){
		int u=i,v=p[(i+pos)%n];
//		printf("%d %d\n",u,v);
		if(find(u)!=find(v)){
			par[u]=v;
			if(++ans>m)
				return 0;
		}
	}
	return 1;
}
il void test(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0; i<n; ++i)
		scanf("%d",p+i);
	memset(cnt,0,n<<2);
	for(int i=0; i<n; ++i){
		cs int x=i+1-p[i];
		--p[i];
		++cnt[x<0?x+n:x];
	}
	int tot=0;
	for(int i=0; i<n; ++i)
		if(cnt[i]+m*2>=n&&check(n,m,i))
			ans[++tot]=i;
	printf("%d",tot);
	for(int i=1; i<=tot; ++i)
		printf(" %d",ans[i]);
	putchar('\n');
}
int main(){
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}