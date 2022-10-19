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
    vector<int> a(N);
    rep(i, N) cin >> a[i];
    string S;
    cin >> S;
    vector<bool> able(3, false);
    each(e, S){
        if(e == '+') able[0] = true;
        if(e == '-') able[1] = true;
        if(e == '*') able[2] = true;
    }

    if(sz(S) == 1){
        rep(i, N){
            cout << a[i];
            if(i < N-1) cout << S;
        }
        cout << '\n';
        return 0;
    }

    if(!able[0]){
        rep(i, N){
            if(i > 0) cout << (a[i] == 0? '-' : '*');
            cout << a[i];
        }
        cout << '\n';
        return 0;
    }

    if(!able[2]){
        rep(i, N){
            cout << a[i];
            if(i < N-1) cout << '+';
        }
        cout << '\n';
        return 0;
    }

    vector<char> ans(N-1, '+');
    int ptr = 0;
    while(ptr < N){
        if(a[ptr] == 0) {ptr++; continue;}
        int k = 0;
        while(ptr+k < N && a[ptr+k] > 0) k++;

        int prd = 1;
        vector<int> ids;
        rep2(i, ptr, ptr+k-1){
            prd *= a[i];
            if(prd > 1000000) prd = 0;
            if(a[i] > 1) ids.eb(i);
        }

        if(prd == 0){
            rep2(i, ids.front(), ids.back()-1) ans[i] = '*';
            ptr += k;
            continue;
        }

        ids.eb(ptr+k);

        int n = sz(ids);
        vector<int> dp(n, -inf), pre(n+1, -1);
        dp[0] = 0;
        rep(i, n-1){
            int now = a[ids[i]];
            rep2(j, i+1, n-1){
                int tmp = now+ids[j]-ids[j-1]-1;
                if(chmax(dp[j], dp[i]+tmp)) pre[j] = i;
                now *= a[ids[j]];
            }
        }

        int pos = n-1;
        while(pos > 0){
            int l = pre[pos], r = pos-1;
            rep2(i, ids[l], ids[r]-1){
                ans[i] = '*';
            }
            pos = l;
        }

        ptr += k;
    }

    rep(i, N){
        cout << a[i];
        if(i < N-1) cout << ans[i];
    }
    cout << '\n';
}