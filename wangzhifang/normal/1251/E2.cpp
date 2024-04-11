#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
#define max_n 200000
vector<int> a[max_n+1];
priority_queue<int> q;
__inline__ __attribute__((always_inline)) void test(){
	int n,m,p;
	scanf("%d",&n);
	for(int i=0; i<n; ++i,a[m].push_back(p))
		scanf("%d%d",&m,&p);
	while(!q.empty())
		q.pop();
	ll ans=0;
	for(int i=n; i>=0; --i){
		for(int p:a[i])
			q.push(-p);
		while(q.size()>n-i){
			ans-=q.top();
			q.pop();
		}
	}
	printf("%lld\n",ans);
	for(int i=0; i<=n; ++i)
		a[i].clear();
}
int main(){
	int t;
	for(scanf("%d",&t); t; --t,test());
}