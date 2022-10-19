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

int main(){
    int N, Q; cin >> N >> Q;

    map<pii, int> mp, es;
    set<pii> s1, s2;

    while(Q--){
        char q; cin >> q;

        if(q == '+'){
            int u, v; char c; cin >> u >> v >> c; u--, v--;
            int x = c-'a';

            if(es.count(pii(v, u))){
                s1.emplace(u, v), s1.emplace(v, u);
                int y = es[pii(v, u)];

                if(x == y){
                    s2.emplace(u, v), s2.emplace(v, u);
                }
            }

            es[pii(u, v)] = x;
        }
        else if(q == '-'){
            int u, v; cin >> u >> v; u--, v--;
            int x = es[pii(u, v)];

            if(es.count(pii(v, u))){
                s1.erase(pii(u, v)), s1.erase(pii(v, u));
                int y = es[pii(v, u)];

                if(x == y){
                    s2.erase(pii(u, v)), s2.erase(pii(v, u));
                }
            }

            es.erase(pii(u, v));
        }
        else{
            int x; cin >> x;
            if(x&1) cout << (!s1.empty()? "YES\n" : "NO\n");
            else cout << (!s2.empty()? "YES\n" : "NO\n");
        }
    }
}