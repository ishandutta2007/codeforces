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

Vi split(const Vi& seq, vector<Vi>& lds) {
    Vi dp, ind, par;
    lds.clear();

    rep(i, 0, sz(seq)) {
        int pos = int(lower_bound(all(dp), seq[i]) - dp.begin());

        if (pos == sz(dp)) {
            dp.pb(seq[i]);
            ind.pb(i);
            lds.emplace_back();
        } else {
            dp[pos] = seq[i];
            ind[pos] = i;
        }

        par.pb(pos > 0 ? ind[pos-1] : -1);
        lds[pos].pb(seq[i]);
    }

    int i = ind.back();
    Vi lis;

    while (i != -1) {
        lis.pb(seq[i]);
        i = par[i];
    }

    reverse(all(lis));
    return lis;
}

Vi filter(const Vi& seq, const Vi& sub) {
    Vi ret;
    int i = 0;
    each(c, seq) {
        if (i >= sz(sub) || sub[i] != c) {
            ret.pb(c);
        } else {
            i++;
        }
    }
    return ret;
}

void handle() {
    int n; cin >> n;
    Vi seq(n);
    each(s, seq) cin >> s;

    vector<Vi> ans;

    while (!seq.empty()) {
        vector<Vi> lds;
        Vi lis = split(seq, lds);

        if (sz(lis)*(sz(lis)+1)/2 < sz(seq)) {
            ans.insert(ans.end(), all(lds));
            break;
        }

        ans.pb(lis);
        seq = filter(seq, lis);
    }

    cout << sz(ans) << '\n';
    each(a, ans) {
        cout << sz(a) << ' ';
        each(k, a) cout << k << ' ';
        cout << '\n';
    }
}

void run() {
    int t; cin >> t;
    while (t--) handle();
}