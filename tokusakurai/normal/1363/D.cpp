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
const ll MOD = 1000000007;
//const ll MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const double pi = acos(-1.0);
const double EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, K;
        cin >> N >> K;
        vector<int> ids[K];
        rep(i, K){
            int c; cin >> c;
            ids[i].resize(c);
            rep(j, c) {cin >> ids[i][j]; ids[i][j]--;}
        }
        int l = 0, r = N; //[l, r)
        int M;
        cout << "? " << N;
        rep(i, N) cout << ' ' << i+1; cout << endl;
        cin >> M;
        while(r-l > 1){
            int m = (l+r)/2;
            int tmp;
            cout << "? " << r-m;
            rep2(i, m, r-1) cout << ' ' << i+1; cout << endl;
            cin >> tmp;
            (tmp == M? l : r) = m;
        }
        int ans[K];
        rep(i, K){
            bool flag = false;
            for(auto &e: ids[i]) if(e == l) flag = true;
            if(!flag) {ans[i] = M; continue;}
            bool used[N];
            fill(used, used+N, false);
            for(auto &e: ids[i]) used[e] = true;
            cout << "? " << N-sz(ids[i]);
            rep(i, N){
                if(!used[i]) cout << ' ' << i+1;
            }
            cout << endl;
            cin >> ans[i];
        }
        cout << "!";
        rep(i, K) cout << ' ' << ans[i]; cout << endl;
        string res;
        cin >> res;
        if(res == "Incorrect") return 0;
    }
}