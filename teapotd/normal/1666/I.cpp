#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
using Vi  = vector<int>;
using Pii = pair<int,int>;
#define mp make_pair
#define pb push_back
#define x  first
#define y  second
#define rep(i,b,e) for(int i=(b); i<(e); i++)
#define each(a,x)  for(auto& a : (x))
#define all(x)     (x).begin(),(x).end()
#define sz(x)      int((x).size())
#define tem template<class t,class u,class...w> auto
#define pri(x,y,z) tem operator<<(t&o,u a)->decltype(z,o) { o << *x; y; z; return o << x[1]; }
pri("{}",, a.print())
pri("()",, o << a.x << ", " << a.y)
pri("[]", auto d=""; for (auto i : a) (o << d << i, d = ", "), all(a))
void DD(...) {}
tem DD(t s, u a, w... k) {
    for (int b=1; cerr << *s++, *s && *s - b*44;) b += 2 / (*s*2 - 81);
    cerr << ": " << a; DD(s, k...);
}
#ifdef LOC
#define deb(...) DD("[,\b :] "#__VA_ARGS__, __LINE__, __VA_ARGS__), cerr << endl
#else
#define deb(...)
#endif
#define DBP(...) void print() { DD(#__VA_ARGS__, __VA_ARGS__); }

bool dig(int x, int y) {
    cout << "DIG " << x << " " << y << endl;
    bool res;
    cin >> res;
    return res;
}

int scan(int x, int y) {
    cout << "SCAN " << x << " " << y  << endl;
    int res;
    cin >> res;
    return res;
}

Pii get_vals(int sum, int dist) {
    if (sum % 2 == 0) {
        int r = dist/2;
        return {sum/2 - r, sum/2 + r};
    } else {
        int r = (dist - 1) / 2;
        return {sum/2 - r, sum/2 + 1 + r};
    }
}

void solve() {
	int n, m;
    cin >> n >> m;
    int sum = scan(1, 1) + 4;
    int sum2 = scan(n, 1) + 2;
    int sumy = (sum + sum2 - 2*n) / 2;
    int sumx = sum - sumy;

    deb(sumx, sumy);

    int distx = scan(sumx/2, 1) - (sumy - 2);
    Pii X = get_vals(sumx, distx);
    int disty = scan(1, sumy/2) - (sumx - 2);
    Pii Y = get_vals(sumy, disty);

    if (dig(X.x, Y.x)) {
        dig(X.y, Y.y);
    } else {
        dig(X.x, Y.y);
        dig(X.y, Y.x);
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(10);

	int t = 1;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}

    return 0;
}