#pragma GCC optimize("Ofast")

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

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair <int, int> pii;

const int inf = (int)1e9;

signed main() {
    sync;
	int n, m;
	cin >> n >> m;
	vector<string> a;
	a.resize(n);
	F(i, 0, n)cin >> a[i];
	int lx = inf, ly = inf, rx = -inf, ry = -inf;
	F(i, 0, n){
		F(j, 0, m){
			if(a[i][j] == 'W')cont;
			if(i < lx || (i == lx && j < ly)){lx = i; ly = j;}
			if(i > rx || (i == rx && j > ry)){rx = i; ry = j;}
		}
	}
	int h = (rx - lx + 1)/2;
	cout << lx + 1 + h << ' ' << ly + 1 + h << endl;
    return 0;
}