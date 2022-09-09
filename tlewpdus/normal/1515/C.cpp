#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int N, M, X;
int H[100100];
priority_queue<pii,vector<pii>,greater<pii>> pq;

int main () {
	int tt, ttt;

	scanf("%d",&ttt);
	for (tt=1;tt<=ttt;tt++) {
		scanf("%d%d%d",&N,&M,&X);
		while(!pq.empty()) pq.pop();
		for (int i=0;i<M;i++) {
			pq.emplace(0,i);
		}
		puts("YES");
		for (int i=0;i<N;i++) {
			int h;
			scanf("%d",&h);
			pii tmp = pq.top();
			pq.pop();
			printf("%d ",tmp.second+1);
			pq.push({tmp.first+h,tmp.second});
		}puts("");
	}

	return 0;
}