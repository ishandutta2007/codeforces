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
#define mp make_pair/////////////////////////////////////////////
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

int n, m, half;
ll grid[20][20];
ll wanted, ans;
vector<map<ll, int>> seen;

void track1(int i, int j, ll val) {
    if (i >= n || j >= m) return;
    val ^= grid[i][j];

    if (i+j < half) {
        track1(i+1, j, val);
        track1(i, j+1, val);
    } else {
        seen[i][val]++;
    }
}

void track2(int i, int j, ll val) {
    if (i < 0 || j < 0) return;

    if (i+j > half) {
        val ^= grid[i][j];
        track2(i-1, j, val);
        track2(i, j-1, val);
    } else {
        ans += seen[i][val^wanted];
    }
}

void run() {
    cin >> n >> m >> wanted;
    half = min(n+m-2, 20);

    rep(i, 0, n) {
        rep(j, 0, m) {
            cin >> grid[i][j];
        }
    }

    seen.resize(n+m+5);
    track1(0, 0, 0);
    track2(n-1, m-1, 0);
    cout << ans << endl;
}