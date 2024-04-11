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

constexpr int MAX_P = 2750131+100;
Vi factor(MAX_P+1);

void sieve() {
    for (int i = 2; i*i <= MAX_P; i++)
        if (!factor[i])
            for (int j = i*i; j <= MAX_P; j += i)
                if (!factor[j])
                    factor[j] = i;

    rep(i,0,MAX_P+1) if (!factor[i]) factor[i]=i;
}

void run() {
    sieve();

    int n; cin >> n;
    Vi cnt(MAX_P+1);

    rep(i, 0, n*2) {
        int e; cin >> e;
        cnt[e]++;
    }

    Vi ans;
    Vi num(MAX_P+1, -1);
    int kek = 1;

    rep(i, 2, MAX_P+1) {
        if (factor[i] == i) {
            num[i] = kek++;
        }
    }

    for (int i = MAX_P; i > 1; i--) {
        int g = i / factor[i];
        int orig = i;

        if (g == 1) {
            orig = g = num[i];
        }

        while (cnt[i] > 0) {
            deb(i, g);
            ans.pb(orig);
            cnt[g]--;
            cnt[i]--;
        }
    }

    each(a, ans) cout << a << ' ';
    cout << '\n';
}