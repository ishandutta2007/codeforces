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

int N;

int query(int a){
    if(a < 0 || a >= N) return inf;
    cout << "? " << a+1 << endl;
    int ret; cin >> ret; return ret-1;
}

void answer(int a){
    cout << "! " << a+1 << endl;
}

int main(){
    cin >> N;

    if(N == 1) {answer(0); return 0;}

    vector<int> a(N, -1);
    a[0] = query(0), a[1] = query(1);

    if(a[0] < a[1]) {answer(0); return 0;}

    int L = 0, R = N-1;
    while(R-L > 1){
        int M = (L+R)/2;
        if(query(M) < query(M+1)) R = M;
        else L = M;
    }

    answer(R);
}