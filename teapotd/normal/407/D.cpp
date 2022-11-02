#define _USE_MATH_DEFINES
#include<bits/stdc++.h>//////////////////////////////////////////
#define deb(...)/////////////////////////////////////////////////
#define DBP(...)/////////////////////////////////////////////////
#ifdef LOC///////////////////////////////////////////////////////
#include"debuglib.h"/////////////////////////////////////////////
#endif///////////////////////////////////////////////////////////
#define x first//////////////////////////////////////////////////
#define y second/////////////////////////////////////////////////
#define pb push_back/////////////////////////////////////////////
#define sz(x)int((x).size())/////////////////////////////////////
#define each(a,x)for(auto&a:(x))/////////////////////////////////
#define all(x)(x).begin(),(x).end()//////////////////////////////
#define rep(i,b,e)for(int i=(b);i<(e);i++)///////////////////////
using namespace std;using ll=long long;using Pii=pair<int,int>;//
using Vi=vector<int>;void run();int main(){cin.sync_with_stdio///
(0);cin.tie(0);cout<<fixed<<setprecision(18);run();return 0;}////
//-------------------------------------------------------------//

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }

constexpr int MAX_V = 400*400+1;

int n, m, ans;
vector<Vi> mat, lim;
bitset<405> seen[MAX_V];
int hei[401][401];

void solve(int bottom) {
    each(s, seen) s.reset();

    rep(i, bottom, n) rep(j, 0, m) {
        int val = mat[i][j];
        int close = (seen[val][m-j] ? j : m-seen[val]._Find_next(m-j));
        seen[val].set(m-j);
        lim[i][j] = (i > bottom ? lim[i-1][j] : -1);
        lim[i][j] = max(lim[i][j], close);
    }

    rep(left, 0, m) {
        int top = n-1;
        bool ok = 1;
        rep(right, left, m) {
            while (lim[top][right] >= left) {
                if (top == bottom) {
                    ok = 0;
                    break;
                }
                top--;
            }
            hei[left][right] = (ok ? top-bottom+1 : 0);
        }
    }

    each(s, seen) s.reset();

    rep(i, bottom, n) for (int j = m-1; j >= 0; j--) {
        int val = mat[i][j];
        int close = (seen[val][j] ? j : seen[val]._Find_next(j));
        seen[val].set(j);
        lim[i][j] = (i > bottom ? lim[i-1][j] : m);
        lim[i][j] = min(lim[i][j], close);
    }

    for (int right = m-1; right >= 0; right--) {
        int top = n-1;
        bool ok = 1;
        for (int left = right; left >= 0; left--) {
            while (lim[top][left] <= right) {
                if (top == bottom) {
                    ok = 0;
                    break;
                }
                top--;
            }

            if (ok) {
                int h = min(hei[left][right], top-bottom+1);
                ans = max(ans, (right-left+1)*h);
            }
        }
    }
}

void run() {
    cin >> n >> m;
    mat.resize(n, Vi(m));
    lim.resize(n, Vi(m));
    rep(i, 0, n) rep(j, 0, m) cin >> mat[i][j];
    rep(i, 0, n) solve(i);
    cout << ans << endl;
}