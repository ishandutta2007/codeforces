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

int n;
ll s;

ll minSum(int deg) {
    ll remain = n-1;
    ll ret = 1;
    ll last = 1;

    for (int i = 1; remain > 0; i++) {
        last = min(remain, last*deg);
        remain -= last;
        ret += ll(last) * (i+1);
    }

    return ret;
}

void run() {
    cin >> n >> s;

    if (s < 2*n-1 || s > ll(n)*(n+1)/2) {
        cout << "No\n";
        return;
    }

    int maxDeg = 1;
    while (minSum(maxDeg) > s) maxDeg++;
    deb(maxDeg);

    Vi counts(n, 1);
    ll sum = ll(n)*(n+1) / 2;

    int to = 1, from = n-1;

    while (sum > s) {
        if (counts[to] >= ll(counts[to-1])*maxDeg) to++;
        if (counts[from] <= 0) from--;
        assert(to < from);

        if (sum+to-from < s) {
            to = int(s+from-sum);
        }

        counts[from]--;
        counts[to]++;
        sum += to-from;
    }

    assert(sum == s);
    cout << "Yes\n";
    int seen = 0;

    rep(i, 1, n) {
        rep(j, 0, counts[i]) {
            int p = seen + j/maxDeg + 1;
            cout << p << ' ';
        }
        seen += counts[i-1];
    }

    cout << endl;
}