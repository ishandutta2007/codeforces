#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
#define max_n 100000
int a[7],cnt[max_n+1];
pair<int,int>t[max_n*6+1];
il void test(){
	for(int i=1; i<=6; ++i)
		scanf("%d",a+i);
	int n,m=0;
	scanf("%d",&n);
	for(int i=1,x; i<=n; ++i){
		scanf("%d",&x);
		for(int j=1; j<=6; ++j)
			t[++m]=make_pair(x-a[j],i);
	}
	sort(t+1,t+m+1),memset(cnt,0,sizeof(cnt));
	int tot=0,ans=2147483647;
	for(int l=1,r=0; l<=m; ++l){
		while(tot<n){
			if(r==m){
				printf("%d\n",ans);
				return;
			}
			int p=t[++r].second;
			if(cnt[p])
				++cnt[p];
			else
				++cnt[p],++tot;
		}
		int d=t[r].first-t[l].first;
		d<ans&&(ans=d);
		if(!--cnt[t[l].second])
			--tot;
	}
	printf("%d\n",ans);
}
int main(){
	test();
//	int t;
//	for(scanf("%d",&t); t; test(),--t);
	return 0;
}