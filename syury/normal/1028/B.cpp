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

signed main() {
    sync;
	int n, m;
	cin >> n >> m;
	string a = "5";
	int len = 1;
	n -= 5;
	while(n > 0){
		n -= 4;
		a += '4';
		++len;
	}
	reverse(all(a));
	cout << a << '\n';
	F(i, 0, len)cout << '5';
    return 0;
}