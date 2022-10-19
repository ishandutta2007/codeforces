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
    int N; cin >> N;

    int ans = 0, cnt = 0;

    rep(i, 2*N){
        string S; cin >> S;
        vector<int> x = {100, 10, 1};
        int t = 0;

        for(int j = 0; ; j++){
            if(S[j] == '.'){
                rep(k, 3){
                    t += x[k]*(S[j+1+k]-'0');
                }
                break;
            }
        }

        if(t > 0) cnt++;
        ans += t;
    }

    int l = max(0, cnt-N), r = min(N, cnt);

    if(ans > 1000*r) ans -= 1000*r;
    else if(ans < 1000*l) ans = 1000*l-ans;
    else ans = min(ans%1000, 1000-ans%1000);

    cout << ans/1000 << '.';
    string S = to_string(ans%1000);
    while(sz(S) < 3) S = '0'+S;

    cout << S << '\n';
}