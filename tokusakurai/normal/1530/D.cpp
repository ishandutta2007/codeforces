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
        vector<int> b(N, -1);
        vector<vector<int>> ids(N);

        rep(i, N){
            cin >> a[i]; a[i]--;
            ids[a[i]].eb(i);
        }

        vector<bool> used(N, false);
        rep(i, N){
            if(ids[i].empty() && !used[a[i]]){
                used[a[i]] = true;
                b[i] = a[i];
            }
        }

        rep(i, N){
            if(!empty(ids[i]) && !used[i]){
                used[i] = true;
                b[ids[i][0]] = i;
            }
        }

        set<int> s1, s2, s3;
        rep(i, N){
            if(b[i] == -1 && !used[i]) s1.emplace(i);
            else if(b[i] == -1) s2.emplace(i);
            else if(!used[i]) s3.emplace(i);
        }

        while(!empty(s2)){
            int i = *begin(s2);
            if(!empty(s1)){
                int j = *begin(s1);
                b[i] = j, used[j] = true;
                s2.erase(i), s1.erase(j), s2.emplace(j);
            }
            else{
                int j = *begin(s3);
                b[i] = j, used[j] = true;
                s2.erase(i), s3.erase(j);
            }
        }

        int K = 0;
        rep(i, N){
            if(a[i] == b[i]) K++;
        }

        cout << K << '\n';
        rep(i, N) cout << b[i]+1 << (i == N-1? '\n' : ' ');
    }
}