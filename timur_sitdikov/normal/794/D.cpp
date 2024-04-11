#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef complex<double> point;
#define xx real()
#define yy imag()

#define REP(i, a, b) for(int i = (a); i < (int)(b); i++)
#define REPN(i, a, b) for(int i = (a); i <= (int)(b); i++)
#define FA(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define SZ(x) (int)(x).size()
#define BE(x) (x).begin(), (x).end()
#define SORT(x) sort(BE(x))
#define _1 first
#define _2 second

#define x1 gray_cat_x1
#define y1 gray_cat_y1

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int MAXN = 6e5 + 55;

vi g[MAXN];

queue<int> qq;

int used[MAXN];

int dis[MAXN];

int prv[MAXN];

ll cnt[MAXN];

set<int> gg[MAXN];

void bfs(int s){
	while(!qq.empty()){
		qq.pop();
	}
	used[s] = 1;
	qq.push(s);
	dis[s] = 0;
	while(!qq.empty()){
		s = qq.front();
		qq.pop();
		REP(i, 0, SZ(g[s])){
			int to = g[s][i];
			if (!used[to]){
				used[to] = 1;
				dis[to] = dis[s] + 1;
				prv[to] = s;
				qq.push(to);
			}
		}
	}
}

void bfs2(int dir){
	while(!qq.empty()){
		int s = qq.front();
		qq.pop();
		REP(i, 0, SZ(g[s])){
			int to = g[s][i];
			if (!dis[to]){
				dis[to] = dis[s] + dir;
				qq.push(to);
			}
		}
	}
}

void solve(){
	int n, m, a, b;
	scanf("%d%d", &n, &m);
	REP(i, 0, m){
		scanf("%d%d", &a, &b);
		g[a].pb(b);
		g[b].pb(a);
		gg[a].insert(b);
		gg[b].insert(a);
	}
	int sn = 0;
	REPN(i, 1, n){
		if (SZ(g[i]) < n - 1){
			sn = i;
			break;
		}
	}
	
	if (sn == 0){
		printf("YES\n");
		REPN(i, 1, n){
			printf("1 ");
		}
		putchar('\n');
		return;
	}
	
	bfs(sn);
	
	int sp = 0, s = 0;
	
	REPN(i, 1, n){
		if (dis[i] == 2){
			sp = i;
			s = prv[i];
			break;
		}
	}
	
	REPN(i, 1, n){
		dis[i] = 0;
	}
	
	
	
	dis[s] = n;
	dis[sp] = n + 1;
	dis[sn] = n - 1;
	
	//printf("%d %d\n%d %d\n%d %d\n", s, dis[s], sp, dis[sp], sn, dis[sn]);
	
	REP(i, 0, SZ(g[s])){
		int to = g[s][i];
		if (to != sp && to != sn){
			int fl_p = 0, fl_n = 0;
			if (gg[sp].find(to) != gg[sp].end()){
				fl_p = 1;
			}
			if (gg[sn].find(to) != gg[sn].end()){
				fl_n = 1;
			}
			if (fl_p && fl_n){
				dis[to] = dis[s];
			} else if (fl_p){
				dis[to] = dis[sp];
			} else if (fl_n){
				dis[to] = dis[sn];
			} else {
				printf("NO\n");
				return;
			}
		}
	}
	
	while(!qq.empty()){
		qq.pop();
	}
	REPN(i, 1, n){
		if (dis[i] == dis[sp]){
			qq.push(i);
		}
		used[i] = 0;
	}
	bfs2(1);
	
	while(!qq.empty()){
		qq.pop();
	}
	REPN(i, 1, n){
		if (dis[i] == dis[sn]){
			qq.push(i);
		}
		used[i] = 0;
	}
	bfs2(-1);
	
	REPN(i, 1, n){
		cnt[dis[i]]++;
	}
	
	ll m2 = 0ll;
	REP(i, 0, 2 * n){
		if (cnt[i]){
			m2 += cnt[i] * cnt[i + 1];
			m2 += cnt[i] * (cnt[i] - 1) / 2;
		}
	}
	
	if (m2 != (ll)m){
		printf("NO\n");
		return;
	}
	
	REPN(i, 1, n){
		REP(j, 0, SZ(g[i])){
			a = g[i][j];
			if (abs(dis[i] - dis[a]) > 1){
				printf("NO\n");
				return;
			}
		}
	}
	printf("YES\n");
	REPN(i, 1, n){
		printf("%d ", dis[i] + 1);
	}
	putchar('\n');
	
}   

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();    
    }
}