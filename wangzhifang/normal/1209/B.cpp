#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
#define max_n 100
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
int s[max_n+1],a[max_n+1],b[max_n+1];
il void test(){
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%1d",s+i);
	for(int i=1; i<=n; ++i)
		scanf("%d%d",a+i,b+i);
	int now=0;
	for(int i=1; i<=n; ++i)
		pq.push(make_pair(b[i],i)),now+=s[i];
	int ans=now;
	for(int i=1; i<=1000000; ++i){
		pair<int,int> u=pq.top();
		pq.pop();
		b[u.second]+=a[u.second];
		pq.push(make_pair(b[u.second],u.second));
		now-=s[u.second];
		now+=s[u.second]^=1;
		if(u.first!=pq.top().first)
			if(now>ans)
				ans=now;
	}
	printf("%d\n",ans);
}
int main(){
	test();
//	int t;
//	for(scanf("%d",&t); t; test(),--t);
	return 0;
}