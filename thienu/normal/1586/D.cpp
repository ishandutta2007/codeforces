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

int query(vi &v){
    cout << "? ";
    for(int i : v) cout << i+1 << ' ';
    cout << endl;
    cout.flush();
    int x;
    cin >> x;
    x--;
    return x;
}

void answer(vi &v){
    cout << "! ";
    for(int i : v) cout << i+1 << ' ';
    cout << endl;
    cout.flush();
}

void solve(){
    int n;
    cin >> n;
    int tries = 0;
    vi vq(n);
    while(true){
        vq[n-1] = ++tries;
        if(tries == n) break;
        int res = query(vq);
        if(res == -1) break;
    }
    int last_elem = n - tries;
    debug(last_elem);
    vi ans(n);
    ans[n-1] = last_elem;

    for(int i = 0; i < n; i++){
        if(i == last_elem) continue;
        vi qu(n);
        if(i < last_elem){
            for(int j = 0; j < n-1; j++){
                qu[j] = last_elem - i;
            }
        }else{
            qu[n-1] = i - last_elem;
        }
        int x = query(qu);
        ans[x] = i;
    }
    answer(ans);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}