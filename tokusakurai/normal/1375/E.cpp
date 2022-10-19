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
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    map<int, int> mp;
    rep(i, N) mp[A[i]]++;
    int n = 0;
    each(e, mp) e.second = n++;
    rep(i, N) A[i] = mp[A[i]];
    vector<int> id[n];
    rep(i, N) id[A[i]].eb(i);
    
    vector<pii> ans;
    while(true){
        bool flag = false;
        rep(i, n-1){
            if(id[i].back() < id[i+1].front()) continue;
            flag = true;
            int a = sz(id[i]), b = sz(id[i+1]);
            vector<int> inv[b];
            int ptr = 0;
            rep(j, b){
                while(ptr < a && id[i+1][j] > id[i][ptr]) ptr++;
                rep3(k, a-1, ptr) ans.eb(id[i+1][j], id[i][k]);
            }
            vector<int> tmp;
            each(e, id[i]) tmp.eb(e);
            each(e, id[i+1]) tmp.eb(e);
            sort(all(tmp));
            rep(j, a){
                id[i][j] = tmp[j];
                A[tmp[j]] = i;
            }
            rep(j, b){
                id[i+1][j] = tmp[a+j];
                A[tmp[a+j]] = i+1;
            }
        }
        if(!flag) break;
    }

    cout << sz(ans) << '\n';
    each(e, ans){
        cout << e.first+1 << ' ' << e.second+1 << '\n';
    }
}