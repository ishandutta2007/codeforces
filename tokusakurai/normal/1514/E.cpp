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

int query1(int a, int b){
    cout << "1 " << a << ' ' << b << endl;
    int ret; cin >> ret;
    return ret;
}

int query2(int a, vector<int> v){
    int n = sz(v);
    cout << "2 " << a << ' ' << sz(v);
    rep(i, n) cout << ' ' << v[i];
    cout << endl;
    int ret; cin >> ret;
    return ret;
}

void merge_sort(vector<int> &v){
    int n = sz(v), m = n/2;
    if(n == 1) return;
    vector<int> L(begin(v), begin(v)+m), R(begin(v)+m, begin(v)+n);

    merge_sort(L), merge_sort(R);

    int l = m, r = n-m;
    int pl = 0, pr = 0;
    rep(i, n){
        if(pl == l) {v[i] = R[pr++]; continue;}
        if(pr == r) {v[i] = L[pl++]; continue;}

        if(query1(L[pl], R[pr])) v[i] = L[pl++];
        else v[i] = R[pr++];
    }
}

int main(){
    int T; cin >> T;

    while(T--){
        int N; cin >> N;

        vector<int> v(N);
        iota(all(v), 0);
        merge_sort(v);

        vector<int> pre(N);

        int p = N-1;
        rep3(i, N-1, 0){
            chmin(p, i);
            while(p > 0 && query2(v[i], vector<int>(begin(v), begin(v)+p))) p--;
            pre[i] = p;
            if(i < N-1) chmin(pre[i], pre[i+1]);
        }

        rep(i, N) chmin(pre[i], pre[pre[i]]);

        vector<vector<int>> ans(N, vector<int>(N, 0));

        rep(i, N){
            rep2(j, pre[i], N-1){
                ans[v[i]][v[j]] = 1;
            }
        }

        cout << 3 << endl;

        rep(i, N){
            rep(j, N) cout << ans[i][j];
            cout << endl;
        }

        int res; cin >> res;
    }
}