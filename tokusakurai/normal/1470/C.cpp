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

int query(int x){
    cout << "? " << x+1 << endl;
    int y; cin >> y; return y;
}

void answer(int x){
    cout << "! " << x+1 << endl;
}

int main(){
    int N, K;
    cin >> N >> K;
    
    int M = 0;
    while(M*M < N) M++;
    rep(i, M) query(0);
    int D = min(M, N/2-1);

    int pos = 0;
    while(true){
        if(query(pos) > K) break;
        pos += D, pos %= N;
    }

    int l = 0, r = N/2; //(l, r]
    while(r-l > 1){
        int m = (l+r)/2;
        if(query((pos+N-m)%N) <= K) r = m;
        else l = m;
    }

    answer((pos+N-r)%N);
}