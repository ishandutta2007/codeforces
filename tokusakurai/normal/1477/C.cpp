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

    vector<ll> x(N), y(N);
    rep(i, N) cin >> x[i] >> y[i];

    vector<int> p(N);
    iota(all(p), 0);

    rep(i, N){
        int j = i;
        while(j >= 2){
            int a = p[j-2], b = p[j-1], c = p[j];

            ll dx1 = x[a]-x[b], dy1 = y[a]-y[b], dx2 = x[c]-x[b], dy2 = y[c]-y[b];

            if(dx1*dx2+dy1*dy2 <= 0) swap(p[j-1], p[j]), j--;
            else break;
        }
    }

    rep(i, N){
        cout << p[i]+1 << (i == N-1? '\n' : ' ');
    }
}