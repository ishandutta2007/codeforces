// .... .... .....!
// ...... ......!
// .... ....... ..... ..!

#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define sz(x) (int((x).size()))
#define pb push_back
#define all(X) (X).begin(),(X).end()
#define X first
#define Y second

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 22;

int n, m;
int a[maxn], b[maxn];
set<pair<int, vector<int>>> mark;
char s[maxn][maxn];

void go(int col, vector<int> v) {
    rep(i, n) if(v[i] > 2*a[i] || (m-col+1) < 2*a[i]-v[i]) return;
    if(col == m) {
        rep(i, n) if(v[i]+1 < 2*a[i]) return;
        throw 0;
    }
    if(mark.find(make_pair(col, v)) != mark.end()) return;
    mark.insert(make_pair(col, v));

    vector<int> t;
    rep(mask, 1<<n) {
        int cnt = 0, tmp = mask;
        while(tmp) tmp &= tmp + (tmp & -tmp), cnt++;
        if(cnt != b[col]) continue;
        t = v;
        rep(i, n) {
            s[i][col] = (mask >> i & 1) ? '*' : '.';
            while(t[i] % 2 != (mask >> i & 1))
                t[i]++;
        }
        go(col+1, t);
        rep(i, n) {
            s[i][col] = 'X';
            while(t[i] % 2 != (mask >> i & 1))
                t[i]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m;
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];

    rep(i, n) rep(j, m) s[i][j] = 'X';

    try {
        go(0, vector<int>(n, 0));
    } catch(...){};

    rep(i, n) cout << s[i] << endl;

    return 0;
}