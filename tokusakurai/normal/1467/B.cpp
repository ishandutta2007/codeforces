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
    int T; cin >> T;

    while(T--){
        int N; cin >> N;

        vector<int> a(N);
        rep(i, N) {cin >> a[i]; a[i] *= 2;}
        vector<int> b(N, 0);
        int K = 0, M = 0;

        if(N <= 2) {cout << "0\n"; continue;}

        rep2(i, 1, N-2){
            int A = 0;
            if(a[i-1] < a[i] && a[i] > a[i+1]) A++;
            if(a[i-1] > a[i] && a[i] < a[i+1]) A++;
            K += A, b[i] = A;
        }

        if(b[1] || b[N-2]) M = -1;

        rep2(i, 1, N-2){
            int u = min(a[i-1], a[i+1]), v = max(a[i-1], a[i+1]);
            vector<int> c = {u-1, u, u+1, v-1, v, v+1};
            each(e, c){
                int tmp = 0, pre = 0;
                if(i-1 > 0){
                    if(a[i-2] < a[i-1] && a[i-1] > e) tmp++;
                    if(a[i-2] > a[i-1] && a[i-1] < e) tmp++;
                    pre += b[i-1];
                }
                if(i+1 < N-1){
                    if(e < a[i+1] && a[i+1] > a[i+2]) tmp++;
                    if(e > a[i+1] && a[i+1] < a[i+2]) tmp++;
                    pre += b[i+1];
                }
                if(a[i-1] < e && e > a[i+1]) tmp++;
                if(a[i-1] > e && e < a[i+1]) tmp++;
                pre += b[i];
                chmin(M, tmp-pre);
            }
        }

        cout << K+M << '\n';
    }
}