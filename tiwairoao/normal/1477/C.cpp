#include <bits/stdc++.h>

const int N = 5000;

typedef long long ll;

std::vector<int>ans;

bool vis[N + 5]; int x[N + 5], y[N + 5], n;

ll pw2(ll p) {return p * p;}
int main() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++) scanf("%d%d", &x[i], &y[i]);
	
	int nw = 1; ans.push_back(nw), vis[nw] = true;
	for(int i=2;i<=n;i++) {
		int mx = -1; ll dis = 0;
		for(int j=1;j<=n;j++) if( !vis[j] ) {
			if( pw2(x[j] - x[nw]) + pw2(y[j] - y[nw]) > dis )
				dis = pw2(x[j] - x[nw]) + pw2(y[j] - y[nw]), mx = j;
		}
		ans.push_back(nw = mx), vis[nw] = true;
	}
	for(auto p : ans) printf("%d ", p);
}