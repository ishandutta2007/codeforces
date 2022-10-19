#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
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
const double pi = acos(-1.0);
const double EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

template<typename T>
struct Prime{
    Prime() {}

    vector<T> divisors(const T &n) const{
        vector<T> ret;
        for(T i = 1; i*i <= n; i++){
            if(n%i == 0){
                ret.pb(i);
                if(i*i != n) ret.pb(n/i);
            }
        }
        //sort(all(ret));
        return ret;
    }

    vector<pair<T, int>> prime_factor(T n) const{
        vector<pair<T, int>> ret;
        for(T i = 2; i*i <= n; i++){
            int cnt = 0;
            while(n%i == 0) cnt++, n /= i;
            if(cnt > 0) ret.eb(i, cnt);
        }
        if(n > 1) ret.eb(n, 1);
        return ret;
    }

    bool is_prime(const T &n) const{
        if(n == 1) return false;
        for(T i = 2; i*i <= n; i++){
            if(n%i == 0) return false;
        }
        return true;
    }

    vector<bool> Eratosthenes(const int &n) const{
        vector<bool> ret(n+1, true);
        if(n >= 0) ret[0] = false;
        if(n >= 1) ret[1] = false;
        for(int i = 2; i*i <= n; i++){
            if(!ret[i]) continue;
            for(int j = 2; i*j <= n; j++) ret[i*j] = false;
        }
        return ret;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    Prime<int> P;
    while(T--){
        int N;
        cin >> N;
        vector<int> ds = P.divisors(N);
        vector<pii> ps = P.prime_factor(N);
        int n = sz(ps);
        if(n == 1){
            for(auto &e: ds){
                if(e > 1) cout << e << ' ';
            }
            cout << endl << 0 << endl;
        }
        if(n >= 3){
            vector<int> ans[n];
            for(auto &e: ds){
                if(e == 1) continue;
                rep(i, n){
                    if(e%ps[i].first == 0) {ans[i].pb(e); break;}
                }
            }
            set<int> s;
            rep(i, n) s.insert(ps[i].first*ps[(i+1)%n].first);
            rep(i, n){
                for(auto &e: ans[i]){
                    if(!s.count(e)) cout << e << ' ';
                }
                cout << ps[i].first*ps[(i+1)%n].first << ' ';
            }
            cout << endl << 0 << endl;
        }
        if(n == 2){
            if(ps[0].second == 1 && ps[1].second == 1){
                for(auto &e: ds){
                    if(e > 1) cout << e << ' ';
                }
                cout << endl << 1 << endl;
            }
            else{
                set<int> s;
                for(auto &e: ds){
                    if(sz(s) < 2 && e%ps[0].first == 0 && e%ps[1].first == 0) s.insert(e);
                }
                vector<int> ans[2];
                for(auto &e: ds){
                    if(e == 1) continue;
                    if(e%ps[0].first == 0) ans[0].pb(e);
                    else ans[1].pb(e);
                }
                for(auto &e: ans[0]){
                    if(!s.count(e)) cout << e << ' ';
                }
                cout << *s.begin() << ' ';
                for(auto &e: ans[1]){
                    if(!s.count(e)) cout << e << ' ';
                }
                cout << *s.rbegin() << endl << 0 << endl;
            }
        }
    }
}