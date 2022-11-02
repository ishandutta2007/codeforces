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

multiset<int> elems;
vector<ll> smaller(30);

void change(int e, bool add) {
    rep(i, 0, sz(smaller)) {
        if (e < (1 << i)) {
            if (add) smaller[i] += e;
            else smaller[i] -= e;
        }
    }
    if (add) elems.insert(e);
    else elems.erase(elems.find(e));
}

int query() {
    if (sz(elems) <= 1) return 0;
    int ans = sz(elems)-1;
    auto last = elems.begin();

    rep(i, 0, sz(smaller)) {
        auto iter = elems.lower_bound(1 << i);
        if (iter == elems.end()) break;

        if (iter != last) {
            int cur = *iter;
            if (cur > 2*smaller[i]) ans--;
            last = iter;
        }
    }

    return ans;
}

void run() {
    int n; cin >> n;
    while (n--) {
        string t; cin >> t;
        int x; cin >> x;
        change(x, t[0] == '+');
        cout << query() << '\n';
    }
}