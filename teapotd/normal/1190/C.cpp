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

void ans(int v) {
    if (v == 1) cout << "tokitsukaze\n";
    else if (v == 2) cout << "quailty\n";
    else cout << "once again\n";
    exit(0);
}

void run() {
    int n, k; cin >> n >> k;
    string s; cin >> s;

    if (n <= k+1) {
        ans(1);
    }

    set<int> pos[2];
    rep(i, k, n) pos[s[i]-'0'].insert(i);

    bool canInf = 0;

    rep(i, 0, n-k+1) {
        if (i > 0) {
            pos[s[i-1]-'0'].insert(i-1);
            pos[s[i+k-1]-'0'].erase(i+k-1);
        }

        deb(i, pos[0], pos[1]);

        if (pos[0].empty() || pos[1].empty()) {
            ans(1);
        }

        // set 0
        int min0 = min(*pos[0].begin(), i);
        int max0 = max(*pos[0].rbegin(), i+k-1);
        int min1 = *pos[1].begin();
        int max1 = *pos[1].rbegin();

        if (max0-min0+1 > k && max1-min1+1 > k) {
            canInf = 1;
        }

        // set 1
        min1 = min(*pos[1].begin(), i);
        max1 = max(*pos[1].rbegin(), i+k-1);
        min0 = *pos[0].begin();
        max0 = *pos[0].rbegin();

        if (max0-min0+1 > k && max1-min1+1 > k) {
            canInf = 1;
        }
    }

    ans(canInf ? -1 : 2);
}