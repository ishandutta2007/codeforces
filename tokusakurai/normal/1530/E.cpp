#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define each(e, v) for(auto &e: v)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const int MOD = 1000000007;
//const int MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

struct io_setup{
    io_setup(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout << fixed << setprecision(15);
    }
} io_setup;

void solve(){
    string S; cin >> S;
    int N = sz(S);

    vector<int> c(26, 0);
    each(e, S){
        c[e-'a']++;
    }
    vector<int> ids;

    rep(i, 26){
        if(c[i] == 1){
            cout << char('a'+i);
            c[i]--;
            rep(j, 26){
                cout << string(c[j], char('a'+j));
            }
            cout << "\n";
            return;
        }
        if(c[i] == N){
            cout << S << '\n';
            return;
        }
        if(c[i] > 0) ids.eb(i);
    }

    if(c[ids[0]] <= N/2+1){
        string ans(N, '.');
        int i = ids[0];
        //cout << i << '\n';
        char x = char('a'+i);
        ans[0] = x;
        rep(j, c[i]-1){
            ans[2*j+1] = x;
        }

        int ptr = 2;
        each(e, ids){
            if(e == i) continue;
            rep(j, c[e]){
                ans[ptr] = char('a'+e);
                ptr++;
                if(ans[ptr] != '.') ptr++;
            }
        }

        cout << ans << '\n';
        return;
    }

    if(sz(ids) == 2){
        int i = ids[0], j = ids[1];
        char x = char('a'+i), y = char('a'+j);
        cout << x << string(c[j], y) << string(c[i]-1, x) << '\n';
        return;
    }

    int i = ids[0], j = ids[1], k = ids[2];
    char x = char('a'+i), y = char('a'+j), z = char('a'+k);
    cout << x << y << string(c[i]-1, x) << z;
    c[i] = 0, c[j]--, c[k]--;
    rep(t, 26){
        cout << string(c[t], char('a'+t));
    }
    cout << "\n";
    return;
}

int main(){
    int T; cin >> T;

    while(T--){
        solve();
    }
}