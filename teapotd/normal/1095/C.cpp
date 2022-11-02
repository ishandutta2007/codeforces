#include<bits/stdc++.h>/////////////////////////////////////////
#define deb(...)////////////////////////////////////////////////
#define DBP(...)////////////////////////////////////////////////
#ifdef LOC//////////////////////////////////////////////////////
#include"debuglib.h"////////////////////////////////////////////
#endif//////////////////////////////////////////////////////////
#define x first/////////////////////////////////////////////////
#define y second////////////////////////////////////////////////
#define pb push_back////////////////////////////////////////////
#define sz(x)int((x).size())////////////////////////////////////
#define each(a,x)for(auto&a:(x))////////////////////////////////
#define all(x)(x).begin(),(x).end()/////////////////////////////
#define rep(i,b,e)for(int i=(b);i<(e);i++)//////////////////////
using namespace std;using ll=int64_t;using Pii=pair<int,int>;///
using Vi=vector<int>;void run();int main(){cin.sync_with_stdio//
(0);cin.tie(0);cout<<fixed<<setprecision(18);run();return 0;}///
//------------------------------------------------------------//

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }

void run() {
    int n, k; cin >> n >> k;
    multiset<int> pows;
    rep(i, 0, 31) if ((n >> i) & 1) pows.insert(i);

    while (sz(pows) < k) {
        auto top = *pows.rbegin();
        pows.erase(prev(pows.end()));

        if (top == 0) {
            cout << "NO\n";
            return;
        }

        pows.insert(top-1);
        pows.insert(top-1);
    }

    if (sz(pows) != k) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    each(p, pows) cout << (1<<p) << ' ';
    cout << endl;
}