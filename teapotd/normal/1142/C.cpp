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

using Point = pair<ll, ll>;
Point operator-(Point a, Point b) { return {a.x-b.x, a.y-b.y}; }
ll cross(Point a, Point b) { return a.x*b.y - a.y*b.x; }

void run() {
    int n; cin >> n;
    vector<Point> elems(n);

    each(e, elems) {
        cin >> e.x >> e.y;
        e.y -= e.x*e.x;
    }

    sort(all(elems));
    int k = 0;

    rep(j, 1, n) {
        if (elems[k].x != elems[j].x) k++;
        elems[k] = elems[j];
    }

    vector<Point> hull;
    elems.resize(k+1);

    each(e, elems) {
        while (sz(hull) >= 2) {
            Point a = hull.rbegin()[1], b = hull.back();
            if (cross(b-a, e-b) < 0) break;
            hull.pop_back();
        }
        hull.pb(e);
    }

    cout << sz(hull)-1 << '\n';
}