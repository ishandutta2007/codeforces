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

int query(int l, int r){
    cout << "? " << l+1 << ' ' << r << endl;
    int x; cin >> x; x--;
    return x;
}

void answer(int x){
    cout << "! " << x+1 << endl;
}

int main(){
    int N; cin >> N;

    int x = query(0, N);

    if(x >= 1 && query(0, x+1) == x){
        int l = 0, r = x; //[l,r)

        while(r-l > 1){
            int m = (l+r)/2;
            (query(m, x+1) == x? l : r) = m;
        }

        answer(l);
    }
    else{
        int l = x, r = N-1; //(l,r]

        while(r-l > 1){
            int m = (l+r)/2;
            (query(x, m+1) == x? r : l) = m;
        }

        answer(r);
    }
}