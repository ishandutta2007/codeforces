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
vector<int> manachar(const T &s){
    int n = s.size();
    vector<int> ret(n);
    int i = 0, j = 0;
    while(i < n){
        while(i-j >= 0 && i+j < n && s[i-j] == s[i+j]) j++;
        ret[i] = j;
        int k = 1;
        while(i-k >= 0 && k+ret[i-k] < j) ret[i+k] = ret[i-k], k++;
        i += k, j -= k;
    }
    return ret;
}

int main(){
    int T; cin >> T;

    while(T--){
        string S; cin >> S;
        int N = sz(S);

        vector<bool> ok(N+1, false);
        ok[0] = true;

        rep(i, N){
            if(ok[i] && S[i] == S[N-1-i]) ok[i+1] = true;
        }

        string T = "$";
        rep(i, N){
            T += S[i], T += '$';
        }

        vector<int> a = manachar(S), b = manachar(T);

        int ans = 0, p = 0, q = 0;

        rep(i, N+1){
            if(ok[i]){
                ans = min(N, i*2);
                p = i, q = min(N-i, i);
            }
        }

        rep(i, N){
            int L = i-a[i]+1, R = i+a[i]-1;
            if(ok[min(L, N-R-1)]){
                if(chmax(ans, 2*a[i]-1+2*min(L, N-R-1))){
                    if(L < N-R-1){
                        p = R+1, q = L;
                    }
                    else{
                        p = N-R-1, q = N-L;
                    }
                }
            }
        }
        
        rep(i, N+1){
            int r = b[2*i];
            if(r == 1) continue;
            r /= 2;

            int L = i-r, R = i+r-1;
            if(ok[min(L, N-R-1)]){
                if(chmax(ans, 2*r+2*min(L, N-R-1))){
                    if(L < N-R-1){
                        p = R+1, q = L;
                    }
                    else{
                        p = N-R-1, q = N-L;
                    }
                }
            }
        }

        cout << S.substr(0, p)+S.substr(N-q) << '\n';
    }
}