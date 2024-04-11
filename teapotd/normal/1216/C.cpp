#define _USE_MATH_DEFINES////////////////////////////////////////
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

struct Rect {
    int x1, y1, x2, y2;

    void flip() {
        swap(x1, y1);
        swap(x2, y2);
    }

    bool inside(Rect r) {
        return x1 >= r.x1 && x2 <= r.x2 && y1 >= r.y1 && y2 <= r.y2;
    }
};

Rect get() {
    Rect r;
    cin >> r.x1 >> r.y1 >> r.x2 >> r.y2;
    return r;
}

void run() {
    Rect w = get();
    Rect b1 = get();
    Rect b2 = get();

    bool ans = !w.inside(b1) && !w.inside(b2);

    if (ans) {
        rep(i, 0, 2) {
            if (b1.y1 > b2.y1) swap(b1, b2);

            if (b1.y2 >= b2.y1) {
                int x1 = max(b1.x1, b2.x1), x2 = min(b1.x2, b2.x2);
                if (x1 <= w.x1 && x2 >= w.x2 && b1.y1 <= w.y1 && b2.y2 >= w.y2) {
                    ans = 0;
                    break;
                }
            }

            w.flip();
            b1.flip();
            b2.flip();
        }
    }

    cout << (ans ? "YES\n" : "NO\n");
}