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

Vi perm, pos;
int n;
vector<Pii> steps;

void op(int i, int j) {
    assert(abs(i-j) >= n/2);
    steps.pb({i, j});
    swap(perm[i], perm[j]);
    swap(pos[perm[i]], pos[perm[j]]);
}

void run() {
    cin >> n;
    perm.resize(n);
    pos.resize(n);

    rep(i, 0, n) {
        int &e = perm[i];
        cin >> e;
        e--;
        pos[e] = i;
    }

    rep(i, 1, n-1) {
        if (pos[i] == i) continue;

        if (abs(pos[i]-i) >= n/2) {
            op(pos[i], i);
        } else {
            if (pos[i] >= n/2) {
                op(pos[i], 0);
                if (i >= n/2) {
                    op(i, 0);
                } else {
                    op(0, n-1);
                    op(i, n-1);
                }
            } else {
                op(pos[i], n-1);
                if (i < n/2) {
                    op(i, n-1);
                } else {
                    op(0, n-1);
                    op(0, i);
                }
            }
        }
    }

    if (perm[0] != 0) {
        op(0, n-1);
    }

    //deb(perm);
    assert(sz(steps) <= 5*n);
    rep(i, 0, n) assert(i == perm[i]);
    cout << sz(steps) << '\n';
    each(s, steps) cout << s.x+1 << ' ' << s.y+1 << '\n';
}