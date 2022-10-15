#include<bits/stdc++.h>
using namespace std;
const int N(100011);
vector<int> adj[N];
int dis[N], vst[N], cnt[2];

int main() {
	int n;
	scanf("%d", &n);
	for(int i(0); i < n - 1; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	vector<int> q;
	q.push_back(1);
	dis[1] = 0;
	vst[1] = 1;
	cnt[0] = 1;
	for(int op(0); op < (int)q.size(); op++) {
		int v(q[op]);
		for(int y : adj[v]) {
			if(!vst[y]) {
				vst[y] = 1;
				dis[y] = dis[v] ^ 1;
				cnt[dis[y]]++;
				q.push_back(y);
			}
		}
	}
	cout << (long long)cnt[0] * cnt[1] - (n - 1) << endl;
}