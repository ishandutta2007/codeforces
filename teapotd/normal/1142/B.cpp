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

void run() {
    int n, m, q; cin >> n >> m >> q;
    Vi perm(n), arr(m);

    each(e, perm) {
        cin >> e;
        e--;
    }

    each(e, arr) {
        cin >> e;
        e--;
    }

    Vi prev(n);
    rep(i, 0, n) prev[perm[(i+1)%n]] = perm[i];

    Vi seen(n, -1), jmp[19];
    jmp[0].resize(m);

    rep(i, 0, m) {
        jmp[0][i] = seen[prev[arr[i]]];
        seen[arr[i]] = i;
    }

    rep(j, 1, 19) {
        jmp[j].resize(m);
        rep(i, 0, m) {
            if (jmp[j-1][i] != -1) jmp[j][i] = jmp[j-1][jmp[j-1][i]];
            else jmp[j][i] = jmp[j-1][i];
        }
    }

    Vi dp(m+1, -1);

    rep(i, 0, m) {
        dp[i+1] = dp[i];

        int remain = n-1;
        int pos = i;

        for (int k = 18; k >= 0 && pos != -1; k--) {
            if (remain >= (1 << k)) {
                pos = jmp[k][pos];
                remain -= (1 << k);
            }
        }

        if (pos == -1) continue;
        dp[i+1] = max(dp[i], pos);
    }

    rep(i, 0, q) {
        int l, r; cin >> l >> r;
        cout << (dp[r] >= l-1);
    }
    cout << endl;
}