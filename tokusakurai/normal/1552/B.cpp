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

bool judge(vector<int> &a, vector<int> &b){
    int A = 0, B = 0;
    rep(i, 5){
        if(a[i] < b[i]) A++;
        else B++;
    }
    return A > B;
}

int main(){
    int T; cin >> T;

    while(T--){
        int N; cin >> N;

        vector<vector<int>> c(N, vector<int>(5));

        rep(i, N){
            rep(j, 5){
                cin >> c[i][j];
                c[i][j]--;
            }
        }

        set<int> s;
        rep(i, N) s.emplace(i);

        int p = 0;

        while(true){
            s.erase(p);
            auto it = begin(s);

            while(!s.empty()){
                int q = *it;
                if(judge(c[p], c[q])){
                    it = s.erase(it);
                }
                else{
                    p = q;
                    break;
                }
            }

            if(empty(s)) break;
        }

        bool flag = true;

        rep(i, N){
            if(i == p) continue;
            if(!judge(c[p], c[i])) flag = false;
        }

        cout << (flag? p+1 : -1) << '\n';
    }
}