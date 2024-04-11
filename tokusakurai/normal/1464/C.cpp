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

template<typename T>
struct F2_Matrix{
    vector<T> A;

    F2_Matrix(int n) : A(n) {}

    int height() const {return sz(A);}

    int width() const {return sz(A.front());}

    inline const T &operator [] (int k) const {return A[k];}

    inline T &operator [] (int k) {return A[k];}

    int normalize(){
        int n = height(), m = width(), check = 0, rank = 0;
        rep(j, m){
            int pivot = check;
            rep2(i, check, n-1){
                if(A[i][j]) pivot = i;
            }
            swap(A[check], A[pivot]);
            if(!A[check][j]) continue;
            rank++;
            rep(i, n){
                if(i == check || !A[i][j]) continue;
                A[i] ^= A[check];
            }
            if(++check == n) break;
        }
        return rank;
    }
};

int main(){
    int N; ll T;
    cin >> N >> T;
    string S;
    cin >> S;

    vector<int> cnt(26, 0);
    ll now = 0;
    now -= (1LL<<(S[N-2]-'a')), now += (1LL<<(S[N-1]-'a'));
    T -= now, T = abs(T);

    rep(i, N-2){
        cnt[S[i]-'a']++;
    }

    rep(i, N-2){
        T += (1LL<<(S[i]-'a'));
    }

    if(T&1) {cout << "No\n"; return 0;}
    T >>= 1;

    rep3(i, 25, 0){
        rep(j, cnt[i]){
            if(T >= (1LL<<i)) T -= (1LL<<i);
        }
    }

    cout << (T == 0? "Yes\n" : "No\n");
}