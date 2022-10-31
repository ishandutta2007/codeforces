#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stack>

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

const lli mod=1e9+7;

int n;
lli w,b,xx,cc[1001],cost[1001],cache[1001][10001];

int main() {
	scanf("%d%lld%lld%lld",&n,&w,&b,&xx);
	
	int cs=0;
	for(int i=1;i<=n;i++) scanf("%lld",cc+i);
	for(int i=1;i<=n;i++) scanf("%lld",cost+i);

	memset(cache,-1,sizeof(cache));
	cache[0][0]=w;
	for(int i=1;i<=n;i++) {
		cs += cc[i];
		deque<pll> que;
		for(int j=0;j<=cs;j++) {
			while(!que.empty() && j-que.front().second > cc[i]) que.pop_front();

			lli nc = (cache[i-1][j]==-1) ? -1 : min(w + b*j, cache[i-1][j] + xx);
			if(cache[i-1][j]!=-1) cache[i][j] = nc;
			if(j>0 && !que.empty()){
				pll cur=que.front();
				lli val = cur.first - (j-cur.second)*cost[i];
				if(val > cache[i][j]) cache[i][j] = val;
			}

			while(!que.empty()) {
				pll cur=que.back();
				if( cur.first - (j-cur.second)*cost[i] > nc ) break;
				que.pop_back();
			}
			que.push_back(pll(nc, j));
		}
	}

	int mx=0;
	for(int i=0;i<=cs;i++) if(cache[n][i]!=-1) mx=i;
	printf("%d\n",mx);

	return 0;
}