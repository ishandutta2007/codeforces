#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N, M;
int D[610][610];
vector<pii> lis[610];

void dijk(int st) {
	vector<vector<int>> q(N,vector<int>());
	vector<int> done(N,0);
	int *d = D[st];
	int base = INF;
	for (pii &tmp : lis[st]) {
		if (tmp.second==st) {
			base = min(base, tmp.first+1);
		}
		else {
			base = min(base, tmp.first);
		}
	}
	for (pii &tmp : lis[st]) {
		int v = tmp.second;
		if (v==st) {
			v = (v+1)%N;
			d[v] = min(d[v],tmp.first+1);
			if (d[v]-base < N) q[d[v] - base].push_back(v);
		}
		else {
			d[v] = min(d[v], tmp.first);
			if (d[v]-base < N) q[d[v] - base].push_back(v);
		}
	}
	d[st] = 0;
	done[st] = 1;
	for (int t=0;t<N;t++) {
		for (int &v : q[t]) {
			if (done[v]) continue;
			done[v] = 1;
			for (pii &tmp : lis[v]) {
				int w =(tmp.second+d[v])%N;
				if (w!=st) {
					if (d[w] > d[v] + tmp.first) {
						d[w] = d[v] + tmp.first;
						if (d[w] - base < N) q[d[w] - base].push_back(w);
					}
				}
				else {
					w = (w+1)%N;
					if (d[w] > d[v] + tmp.first+1) {
						d[w] = d[v] + tmp.first+1;
						if (d[w]-base<N) q[d[w]-base].push_back(w);
					}
				}
			}
			int w = (v+1)%N;
			if (w!=st) {
				if (d[w] > d[v] + 1) {
					d[w] = d[v] + 1;
					if (d[w] - base < N) q[d[w] - base].push_back(w);
				}
			}
			else {
				w = (w+1)%N;
				if (d[w] > d[v] + 2) {
					d[w] = d[v] + 2;
					if (d[w] - base < N) q[d[w] - base].push_back(w);
				}
			}
		}
	}
}

int main () {
	memset(D,0x3f,sizeof(D));
	scanf("%d%d",&N,&M);
	for (int i=0;i<M;i++) {
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		lis[a].emplace_back(c,b);
	}
	for (int i=0;i<N;i++) dijk(i);
	for (int i=0;i<N;i++) {
		for (int j=0;j<N;j++) printf("%d ",D[i][j]);
		puts("");
	}

	return 0;
}