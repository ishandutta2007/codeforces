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
    map<int, int> starts;
    Vi ends;
    int both = 0;

    rep(i, 0, n) {
        string seq; cin >> seq;

        bool first = 1, sec = 1;
        int sum = 0, rev = 0;

        each(c, seq) {
            sum += (c == '(' ? 1 : -1);
            if (sum < 0) {
                first = 0;
                break;
            }
        }

        reverse(all(seq));

        each(c, seq) {
            rev += (c == ')' ? 1 : -1);
            if (rev < 0) {
                sec = 0;
                break;
            }
        }

        if (first && sec) both++;
        else if (first) starts[sum]++;
        else if (sec) ends.pb(rev);
    }

    int ans = both/2;

    each(i, ends) {
        if (starts[i] > 0) {
            starts[i]--;
            ans++;
        }
    }

    cout << ans << endl;
}