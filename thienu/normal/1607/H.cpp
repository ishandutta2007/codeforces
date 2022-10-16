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

struct Dish{
    int a, b, m, idx;
    Dish(int a, int b, int m, int idx) : a(a), b(b), m(m), idx(idx) {}

    friend bool operator< (Dish &x, Dish &y){
        return x.a < y.a || (x.a == y.a && x.b < y.b);
    }

    friend ostream& operator<< (ostream &os, const Dish &x){
        os << '{' << x.a << ',' << x.b << ',' << x.m << ',' << x.idx << '}';
    }
};

void solve(){
    int n;
    cin >> n;
    map<int, vector<Dish>> cats;
    for(int i = 0; i < n; i++){
        int a, b, m;
        cin >> a >> b >> m;
        int x = a + b - m;
        cats[x].push_back(Dish(a, b, m, i));
    }

    int num = 0;
    vpii ans(n);

    for(auto it = cats.begin(); it != cats.end(); it++){
        sort(it->second.begin(), it->second.end());
        int cura = -1e9;
        for(Dish &d : it->second){
            if(d.a > it->first){
                ans[d.idx] = {ans[d.idx].first + d.a - it->first, ans[d.idx].second};
                d.m -= d.a - it->first;
                d.a = it->first;
            }
            if(d.b > it->first){
                ans[d.idx] = {ans[d.idx].first, ans[d.idx].second + d.b - it->first};
                d.m -= d.b - it->first;
                d.b = it->first;
            }
            int mina = max({0, d.a-d.m});
            if(cura < mina){
                cura = d.a;
                num++;
            }
            ans[d.idx] = {ans[d.idx].first + d.a-cura, ans[d.idx].second + d.m-(d.a-cura)};
        }
    }

    cout << num << endl;
    for(pii p : ans){
        cout << p.first << ' ' << p.second << endl;
    }
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