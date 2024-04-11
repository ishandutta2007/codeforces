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
    int N, M, K; cin >> N >> M >> K;

    vector<int> l(M), r(M);
    rep(i, M){
        cin >> l[i] >> r[i]; l[i]--;
    }

    int ans = 0;

    rep2(i, 0, N-K){
        int tmp = 0;
        vector<int> cnt(N+1, 0);

        rep(j, M){
            int D = 0;
            chmax(D, min(r[j], i+K)-max(l[j], i));
            chmax(D, min(r[j], K)-max(l[j], 0));
            tmp += D;

            if(l[j] <= i){
                if(r[j] <= i){
                    cnt[max(0, l[j]-K)]++;
                    if(r[j]-l[j] >= K){
                        cnt[l[j]]--, cnt[r[j]-K]--;
                    }
                    else{
                        cnt[max(0, r[j]-K)]--, cnt[l[j]]--;
                    }
                    cnt[r[j]]++;
                }
                else if(r[j] <= i+K){
                    int d = r[j]-i;
                    cnt[max(0, l[j]+d-K)]++;
                    if(r[j]-l[j] >= K){
                        cnt[l[j]]--, cnt[r[j]-K]--;
                    }
                    else{
                        cnt[max(0, r[j]-K)]--, cnt[l[j]]--;
                    }
                    cnt[r[j]]++;
                }
            }
        }

        chmax(ans, tmp);
        int s = 0;
        rep(j, i){
            s += cnt[j];
            tmp += s, chmax(ans, tmp);
        }
    }

    cout << ans << '\n';
}