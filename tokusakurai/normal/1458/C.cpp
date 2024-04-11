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

vector<vector<int>> I(vector<vector<int>> v){
    int n = sz(v);
    vector<vector<int>> ret(n, vector<int>(n));
    rep(i, n){
        rep(j, n){
            ret[i][v[i][j]] = j;
        }
    }
    return ret;
}

vector<vector<int>> C(vector<vector<int>> v){
    int n = sz(v);
    vector<vector<int>> ret(n, vector<int>(n));
    rep(j, n){
        rep(i, n){
            ret[v[i][j]][j] = i;
        }
    }
    return ret;
}

void transpose(vector<vector<int>> &v){
    int n = sz(v);
    rep(i, n){
        rep(j, i){
            swap(v[i][j], v[j][i]);
        }
    }
}

int main(){
    int t; cin >> t;

    while(t--){
        int N, M; cin >> N >> M;

        vector<vector<int>> a(N, vector<int>(N));
        rep(i, N){
            rep(j, N){
                cin >> a[i][j]; a[i][j]--;
            }
        }

        string S; cin >> S;

        string T;
        int r = 0, d = 0, add = 0;
        rep(i, M){
            if(S[i] == 'R') r++, r %= N;
            if(S[i] == 'L') r += N-1, r %= N;
            if(S[i] == 'D') d++, d %= N;
            if(S[i] == 'U') d += N-1, d %= N;
            if(S[i] == 'I'){
                T += 'I';
                swap(add, r);
            }
            if(S[i] == 'C'){
                T += 'C';
                swap(add, d);
            }
        }

        deque<char> que;
        each(e, T){
            if(!que.empty() && que.back() == e) que.pop_back();
            else que.push_back(e);
        }

        int n = 0;
        while(sz(que) >= 3){
            rep(i, 3) que.pop_front();
            n ^= 1;
        }

        if(n) transpose(a);
        each(e, que){
            if(e == 'I') a = I(a);
            if(e == 'C') a = C(a);
        }

        vector<vector<int>> ans(N, vector<int>(N));
        rep(i, N){
            rep(j, N){
                ans[(i+d)%N][(j+r)%N] = (a[i][j]+add)%N;
            }
        }

        rep(i, N){
            rep(j, N){
                cout << ans[i][j]+1 << ' ';
            }
            cout << '\n';
        }
    }
}