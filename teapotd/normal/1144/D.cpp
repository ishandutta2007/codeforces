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

int cnt[int(2e5+1)];

void run() {
    int n; cin >> n;
    Vi elems(n);

    each(e, elems) {
        cin >> e;
        cnt[e]++;
    }

    int best = 0;
    rep(i, 1, int(2e5+1)) {
        if (cnt[i] > cnt[best]) best = i;
    }

    int pos = 0;
    rep(i, 0, n) {
        if (elems[i] == best) {
            pos = i;
            break;
        }
    }

    cout << n-cnt[best] << '\n';

    for (int i = pos-1; i >= 0; i--) {
        if (elems[i] != best) {
            cout << (elems[i] < best ? 1 : 2) << ' ';
            cout << i+1 << ' ' << i+2 << '\n';
        }
    }

    rep(i, pos+1, n) {
        if (elems[i] != best) {
            cout << (elems[i] < best ? 1 : 2) << ' ';
            cout << i+1 << ' ' << i << '\n';
        }
    }
}