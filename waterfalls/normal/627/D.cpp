#include <bits/stdc++.h>
using namespace std;

int n,k;
int a[200013];
vector<int> adj[200013];
bool vis[200013];

bool bad[200013];
int can[200013];
int high[200013];
int s[200013];

void setup(int x, int p, int T) {
	vis[x] = 1;

	bad[x] = 0;
	can[x] = 1;
	high[x] = 0;
	for (int i: adj[x]) if (i!=p) {
		if (a[i]<T) bad[x] = 1;
		else {
			setup(i,x,T);
			if (bad[i]) {
				bad[x] = 1;
				high[x] = max(high[x],can[i]+high[i]);
			} else can[x]+=can[i];
		}
	}
}

bool go(int x, int p, int T, int cana, bool bada) {
	if (can[x]+high[x]>=k) return true;
	if (can[x]+cana>=k) return true;
	if (!bada && can[x]+cana+high[x]>=k) return true;

	bool badx = 0;
	int cnt = 0;
	int canx = 1;
	vector<int> highx;
	highx.push_back(0);
	for (int i: adj[x]) if (i!=p) {
		if (a[i]<T) badx = 1;
		else {
			if (bad[i]) {
				badx = 1;
				cnt+=1;
				highx.push_back(can[i]+high[i]);
			} else canx+=can[i];
		}
	}
	if (bada) {
		badx = 1;
		cnt+=1;
		highx.push_back(cana);
	} else canx+=cana;
	sort(highx.begin(),highx.end(),greater<int>());

	for (int i: adj[x]) if (i!=p) {
		if (a[i]>=T) {
			if (bad[i]) {
				if (cnt==1) {
					if (go(i,x,T,canx,0)) return true;
				} else {
					int ind = 0;
					if (highx[ind]==can[i]+high[i]) ind+=1;
					if (go(i,x,T,canx+highx[ind],1)) return true;
				}
			} else {
				if (go(i,x,T,canx+highx[0]-can[i],badx)) return true;
			}
		}
	}
	return false;
}

bool solve(int x, int T) {
	setup(x,0,T);
	return go(x,0,T,0,0);
}

bool check(int T) {
	for (int i=1;i<=n;i++) {
		vis[i] = 0;
		bad[i] = 0;
		can[i] = 0;
		high[i] = 0;
	}
	for (int i=1;i<=n;i++) if (!vis[i] && a[i]>=T) {
		if (solve(i,T)) {
			return true;
		}
	}
	return false;
}

int main() {
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n-1;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int low = 0;
	int high = 1000001;
	while (high-low>1) {
		if (check((low+high)/2)) low = (low+high)/2;
		else high = (low+high)/2;
	}
	printf("%d\n",low);

	return 0;
}