#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define I(x, a) for(auto x : a)
#define F(i, l, r) for(auto i = l; i < r; ++i)
#define E(i, l, r) for(auto i = l; i <= r; ++i)
#define DF(i, l, r) for(auto i = l; i >= r; --i)
#define clean(a) memset((a),0,sizeof (a))
#define sync ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) (x).begin(),(x).end()
#define ret return
#define cont continue
#define brk break
#define ins insert
#define sz(a) ((int)(a).size())

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair <int, int> pii;

const int maxn = 22;
int can[maxn][maxn];
int ptr[maxn];
bool dp[1<<maxn];
int tot;
int ans = 0;

int main() {
    sync;
	int n, m;
	cin >> n >> m;
	if(min(n, m) >= 5){
		cout << n * 1ll * m - (n * 1ll * m)%2;
		ret 0;
	}
	if(n > m)swap(n, m);
	if(n == 4){
		if(m != 4){cout << n * 1ll * m - (n * 1ll * m)%2; ret 0;}
	}
	if(n == 3 && m > 6){
		cout << n * 1ll * m - (n * 1ll * m)%2;
		ret 0;
	}
	if(n == 1){
		int a = m/3;
		if(m%3)++a;
		int b = m/3;
		if(m%3 > 1)++b;
		int c = m/3;
		cout << 2 * (a/2) + 2 * (b/2) + 2 * (c/2);
		ret 0;
	}
	if(n == 2 && m > 10){
		cout << n * 1ll * m;
		ret 0;
	}
	F(i, 0, n){
		F(j, 0, m){
			int v = i * m + j;
			F(i1, 0, n){
				F(j1, 0, m){
					int d = abs(i - i1) + abs(j - j1);
					int u = i1 * m + j1;
					if(u < v)cont;
					if(d == 3){
						can[v][ptr[v]++] = u;
					}
				}
			}
		}
	}
	tot = n * m;
	ans = 0;
	dp[0] = true;
	F(mask, 0, (1<<tot)){
		if(!dp[mask])cont;
		ans = max(ans, __builtin_popcount(mask));
		F(i, 0, tot){
			if(mask&(1<<i))cont;
			F(jj, 0, ptr[i]){
				int j = can[i][jj];
				if(mask&(1<<j))cont;
				int nxt = mask|(1<<i)|(1<<j);
				dp[nxt] = true;
			}
		}
	}
	cout << ans;
}