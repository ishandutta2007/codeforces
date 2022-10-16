#include <bits/stdc++.h>

using namespace std;
#define int long long
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
#undef int
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
#define int long long

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
    int n, m;
    cin >> n >> m;
    vector<Dish> v;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        int x = a + b - m;
        v.push_back(Dish(a, b, m, i));
    }

    int num = 0;
    vpii ans(n);

    for(Dish &d : v){
        int req = d.a + d.b - m;
        debug(req);
        if(d.a > req){
            ans[d.idx] = {ans[d.idx].first + d.a - req, ans[d.idx].second};
            d.m -= d.a - req;
            d.a = req;
        }
        if(d.b > req){
            ans[d.idx] = {ans[d.idx].first, ans[d.idx].second + d.b - req};
            d.m -= d.b - req;
            d.b = req;
        }

        num += d.a;
        num -= d.b;
    }

    debug(num, v);

    int i = 0;
    while(!(i == n-1 && v[i].m == 0)){
        debug(i, num, ans, v);
        if(v[i].m == 0){
            i++;
            continue;
        }
        if(num > 0){
            int take = min(v[i].m, num);
            v[i].m -= take;
            v[i].a -= take;
            num -= take;
            ans[i] = {ans[i].first + take, ans[i].second};
        }else if(num < 0){
            int take = min(v[i].m, -num);
            v[i].m -= take;
            v[i].b -= take;
            num += take;
            ans[i] = {ans[i].first, ans[i].second + take};
        }else if(v[i].m == 1){
            v[i].m = 0;
            num--;
            v[i].a -= 1;
            ans[i] = {ans[i].first + 1, ans[i].second};
        }else{
            int take = v[i].m / 2;
            v[i].m -= take * 2;
            v[i].a -= take;
            v[i].b -= take;
            ans[i] = {ans[i].first + take, ans[i].second + take};
        }
    }
    debug(v);

    cout << abs(num) << endl;
    for(pii p : ans){
        cout << p.first << ' ' << p.second << endl;
    }
}
#undef int
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