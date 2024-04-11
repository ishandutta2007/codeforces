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

const int N = (int)1e3 + 3;

int n;
int a[N];
int x[N];
bool used[N];
int ans[N];
int sz = 0;

signed main() {
	sync;
	cin >> n;
	a[0] = 0;
	F(i, 1, n+1)cin >> a[i];
	F(k, 1, n+1){
		fill(used, used + k, false);
		bool g = true;
		F(i, 1, n+1){
			int cx = a[i] - a[i - 1];
			int j = (i - 1)%k;
			if(!used[j]){x[j] = cx; used[j] = true;}
			else{
				if(x[j] != cx)g = false;
			}
		}
		if(g)ans[sz++] = k;
	}
	cout << sz << endl;
	F(i, 0, sz)cout << ans[i] << ' ';
	return 0;
}