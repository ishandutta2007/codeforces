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
    int n, k; cin >> n >> k;
    vector<Pii> songs(n);
    each(s, songs) cin >> s.y >> s.x;

    sort(all(songs));
    reverse(all(songs));

    ll ans = 0, sum = 0;
    multiset<int> avail;

    each(s, songs) {
        avail.insert(s.y);
        sum += s.y;
        while (sz(avail) > k) {
            sum -= *avail.begin();
            avail.erase(avail.begin());
        }
        ans = max(ans, sum*s.x);
    }

    cout << ans << '\n';
}