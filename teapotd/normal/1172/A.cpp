#define _USE_MATH_DEFINES
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
    int n; cin >> n;
    Vi hand(n), que(n);

    each(k, hand) cin >> k;
    each(k, que) cin >> k;

    int seq = n-1;
    while (seq > 0 && que[seq-1] == que[seq]-1 && que[seq-1] > 0) seq--;

    if (que[seq] == 1) {
        int from = n - seq + 1;
        int i = 0;

        set<int> avail;
        each(k, hand) if (k > 0) avail.insert(k);

        while (from <= n) {
            if (!avail.count(from)) break;
            avail.erase(from);
            avail.insert(que[i++]);
            from++;
        }

        if (from == n+1) {
            cout << n - (n-seq+1) + 1 << endl;
            return;
        }
    }

    int blanks = 0;

    rep(i, 0, n) {
        if (que[i] == 0) continue;
        int k = i - que[i] + 2;
        blanks = max(blanks, k);
    }

    cout << blanks+n << endl;
}