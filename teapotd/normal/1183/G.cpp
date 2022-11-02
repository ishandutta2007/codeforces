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

void run() {
    int q; cin >> q;

    while (q--) {
        int n; cin >> n;
        vector<Pii> cnt(n);

        rep(i, 0, n) {
            int a, f; cin >> a >> f;
            cnt[a-1].x++;
            cnt[a-1].y += f;
        }

        sort(all(cnt));

        Vi steps = {cnt.back().x};
        int ans = cnt.back().x;
        int cur = cnt.back().x;

        for (int i = n-2; i >= 0; i--) {
            cur = min(cnt[i].x, cur-1);
            if (cur <= 0) break;
            ans += cur;
            steps.pb(cur);
        }

        priority_queue<int> que;
        int j = n-1;
        int ans2 = 0;

        each(s, steps) {
            while (j >= 0 && cnt[j].x >= s) {
                que.push(cnt[j].y);
                j--;
            }
            ans2 += min(que.top(), s);
            que.pop();
        }

        cout << ans << ' ' << ans2 << '\n';
    }
}