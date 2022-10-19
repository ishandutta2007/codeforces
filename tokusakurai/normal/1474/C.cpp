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
        N *= 2;
        
        map<int, int> mp;
        vector<int> a(N);
        rep(i, N){
            cin >> a[i]; mp[a[i]]++;
        }

        sort(rall(a));

        bool flag = true;

        rep2(i, 1, N-1){
            map<int, int> tmp = mp;
            int ptr = 0;

            int x = a[0]+a[i];
            vector<pii> ans;
            bool ok = true;

            rep(j, N/2){
                while(ptr < N && tmp[a[ptr]] <= 0) ptr++;
                if(ptr == N) {ok = false; break;}
                int A = a[ptr];
                tmp[A]--;
                if(tmp[x-A] <= 0) {ok = false; break;}

                int B = x-A;
                tmp[B]--, ans.eb(A, B), x = max(A, B);
            }

            if(ok){
                flag = false;
                cout << "YES\n";
                cout << a[0]+a[i] << '\n';
                each(e, ans){
                    cout << e.first << ' ' << e.second << '\n';
                }
                break;
            } 
        }

        if(flag) cout << "NO\n";
    }
}