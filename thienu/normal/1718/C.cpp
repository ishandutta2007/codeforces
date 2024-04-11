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

const int N = 2e5 + 5;
// const int N = 20;
bool is_prime[N];
void precomp(){
    is_prime[0] = 0;
    is_prime[1] = 0;
    for(int i = 2; i < N; i++){
        bool ok = true;
        for(int j = 2; j * j <= i; j++){
            if(i % j == 0){
                ok = false;
                break;
            }
        }
        is_prime[i] = ok;
    }
    // debug(range(is_prime, is_prime + N));
}

void solve(){
    int n, q;
    cin >> n >> q;
    vi v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    vi pf;
    for(int i = 2; i <= n-1; i++){
        if(is_prime[i] && n % i == 0){
            pf.push_back(i);
        }
    }

    if(pf.empty()){
        ll sum = accumulate(v.begin(), v.end(), 0ll);
        cout << sum << endl;
        while(q--){
            int x, val;
            cin >> x >> val;
            x--;
            debug(x, val);
            sum -= v[x];
            v[x] = val;
            sum += v[x];
            debug(v);
            cout << sum << endl;
        }
        return;
    }

    debug(pf);

    int m = pf.size();
    vvll pr_sums(m);
    multiset<ll> answers;
    for(int j = 0; j < m; j++){
        int p = pf[j];
        pr_sums[j].resize(n / p);
        for(int i = 0; i < n; i++){
            pr_sums[j][i % (n / p)] += v[i];
        }
        debug(123);
        for(int i = 0; i < (n / p); i++){
            answers.insert(pr_sums[j][i] * (ll) (n / p));
        }
    }
    debug(pr_sums);

    cout << *prev(answers.end()) << endl;

    while(q--){
        int x, val;
        cin >> x >> val;
        x--;
        for(int j = 0; j < m; j++){
            int p = pf[j];
            int r = x % (n / p);
            answers.erase(answers.find(pr_sums[j][r] * (ll) (n / p)));
            pr_sums[j][r] -= v[x];
            pr_sums[j][r] += val;
            answers.insert(pr_sums[j][r] * (ll) (n / p));
        }
        v[x] = val;
        debug(pr_sums);
        cout << *prev(answers.end()) << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precomp();
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}