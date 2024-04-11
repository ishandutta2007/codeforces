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
void Fast_Zeta_Transform(vector<T> &f, bool upper){
    int n = f.size();
    assert((n&(n-1)) == 0);
    for(int i = 1; i < n; i <<= 1){
        for(int j = 0; j < n; j++){
            if(!(j&i)){
                if(upper) f[j] += f[j|i];
                else f[j|i] += f[j];
            }
        }
    }
}

template<typename T>
void Fast_Mobius_Transform(vector<T> &f, bool upper){
    int n = f.size();
    assert((n&(n-1)) == 0);
    for(int i = 1; i < n; i <<= 1){
        for(int j = 0; j < n; j++){
            if(!(j&i)){
                if(upper) f[j] -= f[j|i];
                else f[j|i] -= f[j];
            }
        }
    }
}

template<typename T>
void Fast_Hadamard_Transform(vector<T> &f, bool inverse = false){
    int n = f.size();
    assert((n&(n-1)) == 0);
    for(int i = 1; i < n; i <<= 1){
        for(int j = 0; j < n; j++){
            if(!(j&i)){
                T x = f[j], y = f[j|i];
                f[j] = x+y, f[j|i] = x-y;
            }
        }
    }
    if(inverse) for(auto &e : f) e /= n;
}

int main(){
    int N; cin >> N;

    vector<int> a(1<<24, 0);

    rep(i, N){
        string S; cin >> S;
        vector<int> v;
        each(e, S) v.eb(e-'a');
        sort(all(v));
        v.erase(unique(all(v)), end(v));

        int K = sz(v);
        rep(j, K){
            a[1<<v[j]]++;
        }
        rep(j, K){
            rep(k, j){
                a[(1<<v[j])|(1<<v[k])]--;
            }
        }
        rep(j, K){
            rep(k, j){
                rep(l, k){
                    a[(1<<v[j])|(1<<v[k])|(1<<v[l])]++;
                }
            }
        }
    }

    Fast_Zeta_Transform(a, false);

    int ans = 0;
    each(e, a) ans ^= e*e;

    cout << ans << '\n';
}