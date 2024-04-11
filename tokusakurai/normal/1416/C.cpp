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
    ll N;
    cin >> N;
    int a[N], id[N];
    pii p[N];
    rep(i, N){
        cin >> p[i].first;
        p[i].second = i;
    }
    sort(p, p+N);
    rep(i, N) a[i] = p[i].first, id[i] = p[i].second;
    int x = 0;
    ll ans = 0;
    rep(k, 30){
        ll sum1 = 0, sum2 = 0;
        for(int i = 0; i < N;){
            ll j = 0;
            while(i+j < N && (a[i]>>(k+1)) == (a[i+j]>>(k+1))) j++;
            vector<int> v(j);
            iota(all(v), i);
            sort(all(v), [&](int a, int b){
                return id[a] < id[b];
            });

            ll cnt1 = 0, tmp1 = 0;
            rep(l, j){
                if(a[v[l]]&(1<<k)) cnt1++;
                else tmp1 += cnt1;
            }
            sum1 += tmp1;

            ll cnt2 = 0, tmp2 = 0;
            rep(l, j){
                if(a[v[l]]&(1<<k)) tmp2 += cnt2;
                else cnt2++;
            }
            sum2 += tmp2;

            i += j;
        }
        if(sum2 < sum1) x |= (1<<k), ans += sum2;
        else ans += sum1;
    }
    cout << ans << ' ' << x << endl;
}