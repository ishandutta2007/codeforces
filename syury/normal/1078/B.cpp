//#pragma GCC optimize("Ofast,unroll-loops,sched-spec-load-dangerous,no-stack-protector,peel-loops")
//#pragma GCC target("avx,tune=native")

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

const int N = (int)1e2 + 2;

int cnt[N];
bool ncan[N][N*N], ncan2[N][N*N];
bool can[N][N*N], can2[N][N*N];

signed main() {
	sync;
	int n;
	cin >> n;
	F(i, 0, n){
		int a;
		cin >> a;
		++cnt[a];
	}
	can[0][0] = true;
	F(w, 1, N){
		F(i, 0, N){
			memcpy(ncan[i], can[i], N * N * sizeof(bool));
			memcpy(ncan2[i], can2[i], N * N * sizeof(bool));
		}
		F(add, 1, cnt[w] + 1){
			int cw = add * w;
			ncan[add][cw] = true;
			F(take, add + 1, N){
				F(W, cw, N * N){
					bool kk = can[take - add][W - cw];
					ncan2[take][W] |= kk;
					ncan[take][W] |= kk;
				}
			}
		}
		F(i, 0, N){
			memcpy(can[i], ncan[i], N * N * sizeof(bool));
			memcpy(can2[i], ncan2[i], N * N * sizeof(bool));
		}
	}
	int ws = 0;
	F(i, 0, N)if(cnt[i])++ws;
	int ans = 0;
	DF(k, n, 1){
		bool can = 0;
		bool total = 0;
		F(w, 1, N){
			if(cnt[w] < k)
				continue;
			int cw = w * k;
			if(!can2[k][cw]){
				can = 1;
				if(ws == 2 && cnt[w] == k)
					total = 1;
				if(ws == 1)total = 1;
			}
		}
		if(can){
			ans = max(ans, k);
		}
		if(total)
			ans = n;
	}
	cout << ans;
	return 0;
}