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

int main(){
    int N;
    cin >> N;
    if(N%2 == 0){
        cout << "First" << endl;
        rep(i, 2*N) cout << 1+(i%N) << ' '; cout << endl;
    }
    else{
        cout << "Second" << endl;
        vector<int> p[N];
        rep(i, 2*N){
            int a; cin >> a; a--;
            p[a].pb(i);
        }
        int id[N];
        fill(id, id+N, -1);
        int es[2*N];
        rep(i, N){
            rep(j, 2){
                es[p[i][j]] = p[i][j^1], es[p[i][j^1]] = p[i][j];
            }
        }
        rep(i, 2*N){
            int ptr = i;
            while(id[ptr%N] == -1){
                id[ptr%N] = ptr;
                ptr = es[ptr], ptr += N, ptr %= 2*N;
            }
        }
        ll sum = 0;
        rep(i, N) sum += id[i]+1;
        if(sum%(2*N) == N){
            rep(i, N) id[i] += N, id[i] %= 2*N;
        }
        rep(i, N) cout << id[i]+1 << ' '; cout << endl;
    }
    int res;
    cin >> res;
}