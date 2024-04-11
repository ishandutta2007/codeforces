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

const int N = 102;

int n;
int a[N];

signed main() {
	sync;
	cin >> n;
	F(i, 0, n)cin >> a[i];
	int k = 0;
	while(true){
		int sum = 0, sl = 0;
		bool g = true;
		F(i, 0, n){
			int b = k - a[i];
			if(b < 0)g = false;
			sum += b;
			sl += a[i];
		}
		if(!g){++k; cont;}
		if(sum > sl)brk;
		++k;
	}
	cout << k;
	return 0;
}