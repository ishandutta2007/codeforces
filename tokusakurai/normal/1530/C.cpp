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

        priority_queue<int, vector<int>, greater<int>> que1, que2;
        priority_queue<int> rem;
        int s1 = 0, s2 = 0;

        rep(i, N){
            int a; cin >> a;
            que1.emplace(a), s1 += a;
        }
        rep(i, N){
            int b; cin >> b;
            que2.emplace(b), s2 += b;
        }


        rep(i, N/4){
            s1 -= que1.top(), que1.pop();
            s2 -= que2.top(), rem.emplace(que2.top()), que2.pop();
        }
        //cout << N << ' ' << s1 << ' ' << s2 << '\n';

        int K = N;

        while(s1 < s2){
            que1.emplace(100), s1 += 100;
            rem.emplace(0);
            que2.emplace(rem.top()), s2 += rem.top(), rem.pop();
            K++;
            if(K%4 == 0){
                s1 -= que1.top(), que1.pop();
                s2 -= que2.top(), rem.emplace(que2.top()), que2.pop();
            }
            //cout << K << ' ' << s1 << ' ' << s2 << '\n';
        }

        cout << K-N << '\n';
    }
}