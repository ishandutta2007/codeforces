#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;

int vis[MAXN], fa[MAXN], cnt[MAXN];

vector<int> E[MAXN];

int getfather(int x){
	if (x == fa[x]) return x;
	else return fa[x] = getfather(fa[x]);
}

void read(){

}

int f[MAXN];

void solve(){
	int k;
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; i++)
		vis[i] = 0;
	for(int i = 1; i <= k; i++){
		int x;
		scanf("%d", &x);
		vis[x] = 1;
	}
	for(int i = 1; i <= m; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		E[x].push_back(y);
		E[y].push_back(x);
	}
	for(int i = 1; i <= n; i++){
		cnt[i] = 0, f[i] = 0, fa[i] = i;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < E[i].size(); j++){
			int x = i, y = E[i][j];
			int p = getfather(x), q = getfather(y);
			if (vis[p]) fa[q] = p;
			else fa[p] = q;
		}
	}
	for(int i = 1; i <= n; i++){
		getfather(i);
	}
	for(int i = 1; i <= n; i++){
		cnt[fa[i]]++;
	}
	ll tot = 0, ans = 0, mx = 0;
	for(int i = 1; i <= n; i++)
		if (fa[i] == i){
			if (vis[i]){
				ans += cnt[i] * (cnt[i] - 1) / 2;
				mx = max(mx, (ll)cnt[i]);
			}
			else{
				tot += cnt[i];
			}
		}
	ans = ans - mx * (mx - 1) / 2;
	mx += tot;
	ans = ans + mx * (mx - 1) / 2;
	printf("%lld\n", ans - m);
}

void printans(){

}
	

int main(){
	int T = 1;
//	cin>>T;
	while(T--){
		read();
		solve();
		printans();
	}
	return 0;
}