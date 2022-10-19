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
    string S; cin >> S;

    vector<int> cnt(10, 0);
    each(e, S) cnt[e-'0']++;

    vector<int> pw = {1, 10, 100, 1000};
    vector<int> v = {1, 6, 8, 9};

    int s = 0;
    string ans;

    rep2(e, 1, 9){
        if(e == 1 || e == 6 || e == 8 || e == 9) cnt[e]--;
        rep(i, cnt[e]){
            s *= 10, s += e, s %= 7;
            ans += char('0'+e);
        }
    }

    s *= 10000, s %= 7;

    vector<string> T(7);

    do{
        int K = 0;
        rep(i, 4){
            K += v[i]*pw[i];
        }
        T[K%7] = to_string(K);
    } while(next_permutation(all(v)));

    ans += T[(7-s)%7];
    rep(i, cnt[0]) ans += '0';

    cout << ans << '\n';
}