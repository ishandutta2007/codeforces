#include <bits/stdc++.h>
using namespace std;

#define A first
#define B second
typedef long long ll;

int n,q;
vector<pair<int,int> > L, R;
int whereL[30013], whereR[30013];
ll cost[30013][2];
ll dp[30013];

const ll INF = -3.1e16;

inline ll match(int a, int b) {
	if (a<=0 || b<=0 || a>n || b>n) return INF;
	return (ll) L[a].A*R[b].A;
}

inline void update(int i) {
	if (i<=0 || i>n) return;
	cost[i][0] = match(i,i+1)+match(i+1,i);
	cost[i][1] = max(match(i,i+1)+match(i+1,i+2)+match(i+2,i),match(i,i+2)+match(i+1,i)+match(i+2,i+1));
}

int main() {
	scanf("%d%d",&n,&q);
	for (int i=0;i<=n;i++) {
		L.push_back(make_pair(0,i));
		R.push_back(make_pair(0,i));
	}
	for (int i=1;i<=n;i++) scanf("%d",&L[i].A);
	for (int i=1;i<=n;i++) scanf("%d",&R[i].A);
	sort(L.begin(),L.end());
	sort(R.begin(),R.end());
	for (int i=1;i<=n;i++) {
		whereL[L[i].B] = i;
		whereR[R[i].B] = i;
	}
	for (int i=1;i<=n;i++) update(i);
	for (int Q=0;Q<q;Q++) {
		int a,b;
		scanf("%d%d",&a,&b);
		swap(R[whereR[a]].B,R[whereR[b]].B);
		swap(whereR[a],whereR[b]);
		for (int i=-2;i<=0;i++) {
			update(whereL[a]+i);
			update(whereR[a]+i);
			update(whereL[b]+i);
			update(whereR[b]+i);
		}
		dp[n+1] = 0;
		for (int i=n;i;i--) {
			dp[i] = max(dp[i+2]+cost[i][0],dp[i+3]+cost[i][1]);
			if (L[i].B!=R[i].B) dp[i] = max(dp[i],(ll) L[i].A*R[i].A+dp[i+1]);
		}
		printf("%lld\n",dp[1]);
	}

	return 0;
}