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
    int N, M; cin >> N >> M;

    map<int, int> mpx, mpy;
    vector<int> x(M), y(M);

    mpx[0]++, mpx[N-1]++, mpy[0]++, mpy[N-1]++;

    rep(i, M){
        cin >> x[i] >> y[i]; x[i]--, y[i]--;
        mpx[x[i]]++, mpx[x[i]+1]++, mpy[y[i]]++, mpy[y[i]+1]++;
    }

    if(mpx.count(N)) mpx.erase(N);
    if(mpy.count(N)) mpy.erase(N);

    int H = 0, W = 0;
    each(e, mpx) e.second = H++;
    each(e, mpy) e.second = W++;

    vector<vector<int>> ids(H);
    rep(i, M){
        x[i] = mpx[x[i]], y[i] = mpy[y[i]];
        ids[x[i]].eb(y[i]);
    }

    rep(i, H){
        sort(all(ids[i]));
        ids[i].eb(W);
    }

    vector<pii> p;
    p.eb(0, 0);
    p.eb(inf, inf);

    rep(i, H){
        int pre = 0;
        vector<pii> np;

        each(e, ids[i]){
            int j = lower_bound(all(p), pii(pre, 0))-begin(p);
            if(j > 0 && p[j-1].second >= pre && pre < e){
                np.eb(pre, e-1);
            }
            else if(p[j].first < e){
                np.eb(p[j].first, e-1);
            }
            pre = e+1;
        }

        np.eb(inf, inf);
        swap(p, np);
    }

    bool flag = false;
    each(e, p){
        if(e.first <= W-1 && W-1 <= e.second) flag = true;
    }

    cout << (flag? 2*(N-1) : -1) << '\n';
}