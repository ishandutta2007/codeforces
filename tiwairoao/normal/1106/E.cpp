#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll INF = (1LL<<60);
const int MAXN = 100000 + 5;
const int MAXM = 200 + 5;
int s[MAXN], t[MAXN], d[MAXN], f[MAXN];
ll w[MAXN], dp[MAXM][MAXN];
struct node{
	int ind, d; ll w;
	node(int _i=0, int _d=0, ll _w=0):ind(_i), d(_d), w(_w){}
};
bool operator < (node a, node b) {
	return (a.w == b.w) ? a.d < b.d : a.w < b.w;
}
vector<int>vec[MAXN];
priority_queue<node>que;
int main() {
	int n, m, k; scanf("%d%d%d", &n, &m, &k);
	for(int i=1;i<=k;i++) {
		scanf("%d%d%d%I64d", &s[i], &t[i], &d[i], &w[i]);
		vec[s[i]].push_back(i);
	}
	for(int i=1;i<=n;i++) {
		for(int j=0;j<vec[i].size();j++)
			que.push(node(vec[i][j], d[vec[i][j]], w[vec[i][j]]));
		while( !que.empty() && t[que.top().ind] < i )
			que.pop();
		if( !que.empty() ) f[i] = que.top().ind;
		else f[i] = -1;
	}
/*
	for(int i=1;i<=n;i++)
		printf("%d ", f[i]);
*/
	for(int i=n;i>=1;i--) {
		for(int j=m;j>=1;j--) {
			if( f[i] == -1 ) dp[j][i] = dp[j][i+1];
			else {
				dp[j][i] = min(dp[j][d[f[i]]+1] + w[f[i]], dp[j-1][i+1]);
			}
		}
		if( f[i] == -1 ) dp[0][i] = dp[0][i+1];
		else dp[0][i] = dp[0][d[f[i]]+1] + w[f[i]];
	}
	printf("%I64d\n", dp[m][1]);
}