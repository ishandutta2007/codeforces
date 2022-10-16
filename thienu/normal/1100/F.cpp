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

vi v;
vi ans;

#define clz(x) __builtin_clz(x)

struct Basis{
    vi basis;
    Basis() {}
    Basis(vi &x) {basis = x;}
    Basis(Basis* x) {basis = x->basis;}

    void add(int x){
        for(auto it = basis.begin(); x && it != basis.end(); it++){
            if(clz(*it) > clz(x)){
                basis.insert(it, x);
                return;
            }else if(clz(*it) == clz(x)){
                x ^= *it;
            }
        }
        if(x == 0) return;
        basis.push_back(x);
    }
    
    Basis* merge(Basis* b) {
        Basis* x = new Basis(basis);
        for(int a : b->basis){
            x->add(a);
        }
        return x;
    }

    int best(){
        int cur = 0;
        for(int i : basis){
            if((cur ^ i) > cur){
                cur ^= i;
            }
        }
        return cur;
    }

    size_t size() { return basis.size(); }
};

ostream& operator<<(ostream& os, Basis b){ return os << b.basis; }

struct Query{
    int l, r, idx;
    Query(int l, int r, int idx) : l(l), r(r), idx(idx) {}
};
ostream& operator<<(ostream& os, Query q){ return os << '{' << q.l << ',' << q.r << ',' << q.idx << '}'; }

void get(int lo, int hi, vector<Query> &queries){
    int mid = lo + (hi - lo) / 2;
    vector<Query> l, r, good;
    for(Query p : queries){
        if(p.r < mid) l.push_back(p);
        else if(mid < p.l) r.push_back(p);
        else good.push_back(p);
    }
    debug(lo, hi, mid, l, r, good);
    if(!l.empty()) get(lo, mid-1, l);
    if(!r.empty()) get(mid+1, hi, r);

    vector<Basis*> lsuf, rsuf;
    Basis* cur = new Basis();
    lsuf.push_back(new Basis(cur));
    for(int i = mid-1; i >= lo; i--){
        cur->add(v[i]);
        lsuf.push_back(new Basis(cur));
    }
    cur = new Basis();
    rsuf.push_back(new Basis(cur));
    for(int i = mid; i < hi; i++){
        cur->add(v[i]);
        rsuf.push_back(new Basis(cur));
    }
    debug(lsuf.size(), rsuf.size());

    for(Query query : good){
        Basis* left = lsuf[mid-query.l];
        Basis* right = rsuf[query.r-mid];
        Basis* res = left->merge(right);
        debug(*res);
        ans[query.idx] = res->best();
        delete res;
    }
    for(Basis* &x : lsuf){
        delete x;
    }
    for(Basis* &x : rsuf){
        delete x;
    }
}

void solve(){
    int n;
    cin >> n;
    v.resize(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    int q;
    cin >> q;
    vector<Query> queries;
    for(int i = 0; i < q; i++){
        int x, y;
        cin >> x >> y;
        x--;
        queries.push_back(Query(x, y, i));
    }
    ans.resize(q);
    get(0, n, queries);

    debug(ans);
    for(int i : ans){
        cout << i << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}