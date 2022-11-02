#include<bits/stdc++.h>

using namespace std;
typedef long long lint;
typedef long double ldb;
typedef unsigned long long uli;

#define X first
#define Y second
#define F(i, l, r) for(auto i = l; i != r; i++)
#define Df(i, l, r) for(auto i = l; i != r; i--)
#define I(i, a) for(auto i : a)
#define pb push_back
#define rs resize
#define mk make_pair
#define asg assign
#define all(x) x.begin(),x.end()
#define ret return
#define cont continue
#define brk break
#define ins insert
#define era erase
#define fi0(x) memset(x, 0, sizeof(x))
#define finf(x) memset(x, 127, sizeof(x))
#define y1 adjf
#define tm dhgdg

const int MAXN = 1e3 + 5;

int n, m, W;
vector<list<int> > gr;
vector<int> w, b;
vector<list<int> > cm;
vector<int> tw, tb;
vector<char> ue;
int cc = 0;
int dp[MAXN][MAXN];
bool can[MAXN][MAXN];

void dfs(int v){
	ue[v] = true;
	tw[cc] += w[v]; tb[cc] += b[v];
	cm[cc].pb(v);
	I(u, gr[v]){
		if(!ue[u])dfs(u);
	}
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d%d%d", &n, &m, &W);
	gr.rs(n); w.rs(n); b.rs(n); tw.rs(MAXN); cm.rs(MAXN); tb.rs(MAXN);
	tw.asg(MAXN, 0); tb.asg(MAXN, 0);
	ue.rs(n); ue.asg(n, false);
	F(i, 0, n){
		scanf("%d", &w[i]);
	}
	F(i, 0, n)scanf("%d", &b[i]);
	F(i, 0, m){
		int v, u;
		scanf("%d%d", &v, &u); v--; u--;
		gr[v].pb(u); gr[u].pb(v);
	}
	F(i, 0, n){if(!ue[i]){dfs(i); cc++;}}
	fi0(can); fi0(dp);
	can[0][0] = true;
	F(i, 1, cc + 1){
		F(j, 0, W + 1){
			int prv;
			prv = j - tw[i - 1];
			if(prv >= 0 && can[i - 1][prv]){can[i][j] = true; dp[i][j] = max(dp[i][j], dp[i - 1][prv] + tb[i - 1]);}
			if(can[i - 1][j]){can[i][j] = true; dp[i][j] = max(dp[i][j], dp[i - 1][j]);}
			I(v, cm[i - 1]){
				prv = j - w[v];
				if(prv >= 0 && can[i - 1][prv]){can[i][j] = true; dp[i][j] = max(dp[i][j], dp[i - 1][prv] + b[v]);}
			}
		}
	}
	int ans = 0;
	F(j, 0, W + 1){
		if(can[cc][j] && dp[cc][j] > ans)ans = dp[cc][j];
	}
	printf("%d", ans);
	ret 0;
}