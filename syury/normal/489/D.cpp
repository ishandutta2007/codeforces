#include<bits/stdc++.h>

using namespace std;
typedef long long lint;
typedef long double ldb;
typedef unsigned long long uli;

#define X first
#define Y second
#define F(i, l, r) for(auto i = l; i != r; i++)
#define Df(i, l, r) for(auto i = l; i != r; i--)
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
#define y1 adjf

const int MAXN = 3002;

int cnt[MAXN][MAXN];
vector<list<int> > out;
int n, m;
vector<pair<int, int> > e;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d%d", &n, &m);
	out.rs(n); e.rs(m);
	F(i, 0, m){
		int v, u;
		scanf("%d%d", &v, &u); v--; u--;
		out[v].pb(u);
		e[i] = mk(v, u);
	}
	fi0(cnt);
	F(i, 0, m){
		int a = e[i].X;
		int v = e[i].Y;
		F(it, out[v].begin(), out[v].end()){
			int u = *it;
			cnt[a][u]++;
		}
	}
	lint ans = 0ll;
	F(i, 0, n){
		F(j, 0, n){
			if(i == j)
				cont;
			ans += cnt[i][j] * 1ll * (cnt[i][j] - 1)/2;
		}
	}
	printf("%lld", ans);
	ret 0;
}