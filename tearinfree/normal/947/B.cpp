#include <cstdio>
#include <algorithm>
#include <utility>
#include <queue>
#include <vector>

using namespace std;
typedef long long lli;
typedef pair<int,lli> pil;

int n;
lli va[100001],ta[100001];

int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",va+i);
	for(int i=1;i<=n;i++) scanf("%lld",ta+i),ta[i]+=ta[i-1];

	priority_queue<pil,vector<pil>,greater<pil>> que;
	int c=0;
	for(int i=1;i<=n;i++) {
		c++;
		int lo=0,up=n+1;
		while(up-lo>1) {
			int md=(up+lo)>>1;
			if(ta[md] - ta[i-1] <= va[i]) lo=md;
			else up=md;
		}
		que.push(pil(lo+1, va[i] - (ta[lo] - ta[i-1])));
		
		lli s=0;
		while(!que.empty() && que.top().first <= i) {
			s += que.top().second; c--; que.pop();
		}
		s += 1ll * c * (ta[i]-ta[i-1]);
		printf("%lld ",s);
	}
	
	return 0;
}