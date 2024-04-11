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

int n, m;
Vi wanted(n);
vector<Vi> offers;

bool check(int nDays) {
    Vi rest = wanted;
    int money = nDays;
    int totalMoney = nDays;

    for (int d = nDays-1; d >= 0; d--) {
        money = min(d+1, money);

        each(f, offers[d]) {
            int spent = min(money, rest[f]);
            money -= spent;
            totalMoney -= spent;
            rest[f] -= spent;
        }
    }

    int kek = accumulate(all(rest), 0);
    return kek*2 <= totalMoney;
}

void run() {
    cin >> n >> m;
    wanted.resize(n);
    each(w, wanted) cin >> w;

    offers.resize(1e6+5);

    rep(i, 0, m) {
        int d, t; cin >> d >> t;
        offers[d-1].pb(t-1);
    }

    int begin = 0, end = 1e6;

    while (begin+1 < end) {
        int mid = (begin+end-1) / 2;
        if (check(mid)) {
            end = mid+1;
        } else {
            begin = mid+1;
        }
    }

    cout << begin << '\n';
}