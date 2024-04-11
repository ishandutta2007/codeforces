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

    vector<int> a(N), cnt(N, 0);
    rep(i, N){
        cin >> a[i]; cnt[--a[i]]++;
    }

    int K = 600;
    vector<int> check;
    rep(i, N){
        if(cnt[i] > K/2) check.eb(i);
    }

    vector<int> L(Q), R(Q), M(Q, 0);
    vector<int> c(N, 0);
    vector<int> tmp;

    rep(i, Q){
        cin >> L[i] >> R[i]; L[i]--;

        if(R[i]-L[i] <= K){
            rep2(j, L[i], R[i]-1){
                chmax(M[i], ++c[a[j]]);
            }
            rep2(j, L[i], R[i]-1) c[a[j]]--;
        }
        else{
            tmp.eb(i);
        }
    }

    vector<int> s(N+1, 0);

    each(e, check){
        rep(i, N) s[i+1] = s[i]+(a[i] == e? 1 : 0);
        
        each(u, tmp){
            chmax(M[u], s[R[u]]-s[L[u]]);
        }
    }

    rep(i, Q){
        //cout << M[i] << ' ';
        cout << max(1, 2*M[i]-(R[i]-L[i])) << '\n';
    }
}