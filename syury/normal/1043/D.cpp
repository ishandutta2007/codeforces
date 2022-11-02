//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,mmx,popcnt")

#include<bits/stdc++.h>
#include<bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define F(i, l, r) for(int i = (l); i < (r); i++)
#define E(i, l, r) for(int i = (l); i <= (r); i++)
#define DF(i, l, r) for(int i = (l); i >= (r); i--)
#define I(x, a) for(auto x : (a))
#define mp make_pair
#define X first
#define Y second
#define clean(x) memset((x), 0, sizeof(x))
#define ret return
#define cont continue
#define brk break
#define ins insert
#define all(x) (x).begin(),(x).end()
#define sync ios_base::sync_with_stdio(false);cin.tie(0)
#define pb push_back
#define y1 fjfg
#define tm shjfhg

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

const int N = (int)1e5 + 5;
const int M = 11;

int32_t a[M][N];
int32_t nxt[M][N];
int32_t lon[N];
int n, m;
ll ans = 0;

signed main() {
	sync;
	scanf("%d%d", &n, &m);
	F(i, 0, m){
		F(j, 0, n){scanf("%d", a[i] + j); --a[i][j];}
		F(j, 0, n){
			if(j == n - 1)nxt[i][a[i][j]] = -1;
			else nxt[i][a[i][j]] = a[i][j+1];
		}
	}
	DF(j, n - 1, 0){
		int x = a[0][j];
		if(j == n - 1){lon[x] = 1; cont;}
		int y = a[0][j+1];
		bool g = true;
		F(i, 0, m)if(nxt[i][x] != y)g = 0;
		if(!g){lon[x] = 1; cont;}
		lon[x] = lon[y] + 1;
	}
	F(bg, 0, n){
		ans += lon[bg];
	}
	cout << ans;
	return 0;
}