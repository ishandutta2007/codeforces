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

struct Point {
    int id, x, y, z;
};

bool inside(Point a, Point b, Point c) {
    return min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x) &&
           min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y) &&
           min(a.z, b.z) <= c.z && c.z <= max(a.z, b.z);
}

void run() {
    int n; cin >> n;
    vector<Point> points(n);

    rep(i, 0, n) {
        auto& p = points[i];
        p.id = i+1;
        cin >> p.x >> p.y >> p.z;
    }

    while (sz(points) > 0) {
        auto p = points.back();
        points.pop_back();
        int best = 0;

        rep(i, 1, sz(points)) {
            if (inside(p, points[best], points[i])) {
                best = i;
            }
        }

        cout << p.id << ' ' << points[best].id << '\n';

        points[best] = points.back();
        points.pop_back();
    }
}