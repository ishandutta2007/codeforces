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

template<typename T>
vector<T> divisors(const T &n){
    vector<T> ret;
    for(T i = 1; i*i <= n; i++){
        if(n%i == 0){
            ret.push_back(i);
            if(i*i != n) ret.push_back(n/i);
        }
    }
    sort(begin(ret), end(ret));
    return ret;
}

template<typename T>
vector<pair<T, int>> prime_factor(T n){
    vector<pair<T, int>> ret;
    for(T i = 2; i*i <= n; i++){
        int cnt = 0;
        while(n%i == 0) cnt++, n /= i;
        if(cnt > 0) ret.emplace_back(i, cnt);
    }
    if(n > 1) ret.emplace_back(n, 1);
    return ret;
}

template<typename T>
bool is_prime(const T &n){
    if(n == 1) return false;
    for(T i = 2; i*i <= n; i++){
        if(n%i == 0) return false;
    }
    return true;
}

//1,2,...,nk
template<typename T>
T coprime(T n, T k){
    vector<pair<T, int>> ps = prime_factor(k);
    int m = ps.size();
    T ret = 0;
    for(int i = 0; i < (1<<m); i++){
        T prd = 1;
        for(int j = 0; j < m; j++){
            if((i>>j)&1) prd *= ps[j].first;
        }
        ret += (__builtin_parity(i)? -1 : 1)*(n/prd);
    }
    return ret;
}

vector<bool> Eratosthenes(const int &n){
    vector<bool> ret(n+1, true);
    if(n >= 0) ret[0] = false;
    if(n >= 1) ret[1] = false;
    for(int i = 2; i*i <= n; i++){
        if(!ret[i]) continue;
        for(int j = i+i; j <= n; j += i) ret[j] = false;
    }
    return ret;
}

vector<int> Eratosthenes2(const int &n){
    vector<int> ret(n+1);
    iota(begin(ret), end(ret), 0);
    if(n >= 0) ret[0] = -1;
    if(n >= 1) ret[1] = -1;
    for(int i = 2; i*i <= n; i++){
        if(ret[i] < i) continue;
        for(int j = i+i; j <= n; j += i) ret[j] = min(ret[j], i);
    }
    return ret;
}

int main(){
    int N; cin >> N;

    int MAX = 1000000;
    vector<int> t = Eratosthenes2(MAX);

    vector<int> ps;

    rep2(i, 2, MAX){
        if(t[i] == i) ps.eb(i);
    }

    int K = sz(ps);
    //cout << K << '\n';

    vector<int> ids(MAX+1, -1);
    rep(i, K){
        ids[ps[i]] = i;
    }

    vector<vector<pll>> range(K);
    vector<ll> ans(K, 0);

    rep(i, N){
        int p; ll a; cin >> p >> a;
        range[ids[p]].eb(0, a);
    }

    ll T; cin >> T;
    
    rep3(i, K-1, 0){
        if(empty(range[i])) continue;

        sort(all(range[i]));
        vector<pll> tmp;
        pll pre = pll(-1, -1);

        each(e, range[i]){
            if(pre.second < e.first){
                if(pre.first != -1) tmp.eb(pre);
                pre = e;
            }
            else{
                pre.second += e.second-e.first;
            }
        }

        if(pre.first != -1) tmp.eb(pre);
        
        while(!empty(tmp)){
            pll &e = tmp.back();
            
            if(e.second > T){
                if(e.first >= T){
                    ans[i] += e.second-e.first;
                    tmp.pop_back();
                }
                else{
                    ans[i] += e.second-T;
                    e.second = T;
                }
            }
            else{
                break;
            }
        }
        
        int p = ps[i]-1;
        
        while(p > 1){
            int k = t[p];
            p /= k;
            each(e, tmp){
                range[ids[k]].eb(e.first+1, e.second+1);
            }
        }
    }
    
    vector<pil> res;

    rep(i, K){
        if(ans[i] > 0) res.eb(ps[i], ans[i]);
    }

    cout << sz(res) << '\n';
    each(e, res){
        cout << e.first << ' ' << e.second << '\n';
    }
}