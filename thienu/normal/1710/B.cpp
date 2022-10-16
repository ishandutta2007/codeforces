#include <bits/stdc++.h>

using namespace std;

#define u_map unordered_map
#define u_set unordered_set
#define u_multiset unordered_multiset

using ll = long long;
using vvi = vector<vector<int>>;
using vi = vector<int>;
using vvll = vector<vector<long long>>;
using vll = vector<long long>;
using vd = vector<double>;
using vvd = vector<vector<double>>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;

template<typename C> struct rge{C l, r;};
template<typename C> rge<C> range(C i, C j) { return rge<C>{i, j}; }
template<typename C> ostream& operator<<(ostream &os, rge<C> &r) { os << '{'; for(auto it = r.l; it != r.r; it++) os << "," + (it == r.l) << *it; os << '}'; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '{' << p.first << "," << p.second << '}'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ","; return os << '}'; }
void dbg_out() { cerr << ']' << endl; }
template<typename A> void dbg_out(A H) { cerr << H; dbg_out(); }
template<typename A, typename B, typename... C> void dbg_out(A H, B G, C... T) { cerr << H << ","; dbg_out(G, T...); }
#ifdef DEBUG
#define debug(...) cerr << "[" << #__VA_ARGS__ << "] = [", dbg_out(__VA_ARGS__)
#else
#define debug(...)
#endif

vll pass(int n, vi &x, vi &p){
    multiset<int> runout;
    vll ans(n);
    ll cur = 0;
    for(int i = 0; i < n; i++){
        ans[i] = cur;
        cur += p[i];
        runout.insert(x[i] + p[i]);
        if(i+1 < n){
            int cur_pos = x[i];
            while(!runout.empty() && *runout.begin() < x[i+1]){
                cur -= (ll) runout.size() * (*runout.begin() - cur_pos);
                cur_pos = *runout.begin();
                runout.erase(runout.begin());
            }
            cur -= (ll) runout.size() * (x[i+1] - cur_pos);
        }
    }
    return ans;
}

void solve(){
    int n;
    ll m;
    cin >> n >> m;
    vector<pair<pii, int>> xp;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        xp.push_back({{a, b}, i});
    }
    sort(xp.begin(), xp.end());
    vi x(n);
    vi p(n);
    vi perm(n);
    for(int i = 0; i < n; i++){
        x[i] = xp[i].first.first;
        p[i] = xp[i].first.second;
        perm[i] = xp[i].second;
    }
    debug(x, p);

    vll rain(n);
    vll rg = pass(n, x, p);
    reverse(x.begin(), x.end());
    for(int i = 0; i < n; i++) x[i] *= -1;
    reverse(p.begin(), p.end());
    vll lf = pass(n, x, p);
    reverse(x.begin(), x.end());
    for(int i = 0; i < n; i++) x[i] *= -1;
    reverse(p.begin(), p.end());
    reverse(lf.begin(), lf.end());
    for(int i = 0; i < n; i++){
        rain[i] = p[i] + lf[i] + rg[i];
    }
    debug(rain);

    vll leftc(n), rightc(n);
    for(int i = 0; i < n; i++){
        if(rain[i] > m){
            rightc[i] = rain[i] - m - (ll) x[i]; // p + x >= leftc
            leftc[i] = rain[i] - m + (ll) x[i]; // p - x >= rightc
        }else{
            rightc[i] = -1e18;
            leftc[i] = -1e18;
        }
    }
    debug(leftc, rightc);

    multiset<ll> leftcs;
    multiset<ll> rightcs;
    for(int i = 0; i < n; i++){
        leftcs.insert(leftc[i]);
    }

    vi ans(n);
    for(int i = 0; i < n; i++){
        ll max_rightc = rightcs.empty() ? -1e18 : *prev(rightcs.end());
        ll max_leftc = leftcs.empty() ? -1e18 : *prev(leftcs.end());
        debug(i, max_leftc, max_rightc, leftcs, rightcs, p[i] + x[i], p[i] - x[i]);
        if(p[i] - x[i] >= max_rightc && p[i] + x[i] >= max_leftc){
            ans[perm[i]] = 1;
        }else{
            ans[perm[i]] = 0;
        }
        leftcs.erase(leftcs.find(leftc[i]));
        rightcs.insert(rightc[i]);
    }
    for(int i : ans){
        cout << i;
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}