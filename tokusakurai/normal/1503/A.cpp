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

bool judge(string S){
    int tmp = 0;
    each(e, S){
        if(e == '(') tmp++;
        else tmp--;
        if(tmp < 0) return false;
    }
    return tmp == 0;
}

int main(){
    int T; cin >> T;

    while(T--){
        int N; string S; cin >> N >> S;

        vector<int> a, b;
        rep(i, N){
            if(S[i] == '1') a.eb(i);
            else b.eb(i);
        }

        if(sz(a)%2 == 1) {cout << "NO\n"; continue;}

        int n = sz(a), m = sz(b);

        string A(N, ')'), B(N, ')');

        rep(i, n/2){
            A[a[i]] = B[a[i]] = '(';
        }
        rep(i, m){
            if(i%2 == 0) A[b[i]] = '(';
            else B[b[i]] = '(';
        }

        //cout << A << ' ' << B << '\n';

        if(judge(A) && judge(B)) cout << "YES\n" << A << '\n' << B << '\n';
        else cout << "NO\n";
    }
}