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
const int MOD = 1000000007;
//const int MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const double pi = acos(-1.0);
const double EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

struct Random_Number_Generator{
    mt19937_64 mt;

    Random_Number_Generator() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}

    int64_t operator () (int64_t l, int64_t r){
        uniform_int_distribution<int64_t> dist(l, r-1);
        return dist(mt);
    }

    int64_t operator () (int64_t r){ 
        return (*this)(0, r);
    }
};

int main(){
    int N;
    cin >> N;
    Random_Number_Generator rnd;
    uint64_t r[N];
    rep(i, N) r[i] = rnd(LLONG_MAX);
    unordered_map<int64_t, int> mp;
    int ptr = 0;
    queue<int> que[N];
    uint64_t hash[N+1];
    int cnt[N];
    fill(hash, hash+N+1, 0), fill(cnt, cnt+N, 0);
    ll ans = 0;
    mp[0]++;
    rep(i, N){
        int a; cin >> a; a--;
        que[a].push(i);
        if(sz(que[a]) > 3){
            while(ptr <= que[a].front()){
                mp[hash[ptr++]]--;
            }
            que[a].pop();
        }
        int pre = cnt[a];
        cnt[a] = (pre+1)%3;
        hash[i+1] = hash[i]+r[a]*(cnt[a]-pre);
        ans += mp[hash[i+1]]++;
    }
    cout << ans << endl;
}