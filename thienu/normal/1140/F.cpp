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

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const int A = 3e5 + 5;
// const int A = 5;

const int BUF = 3e7;

vll ans;

ll cur_ans = 0;
vi parent, szx, szy;
int* where[BUF];
int val[BUF];
int pt = 0;

int find_par(int a){
    if(parent[a] == a) return a;
    return find_par(parent[a]);
}

void merge(int a, int b){
    int oa = a, ob = b;
    a = find_par(a), b = find_par(b);
    if(a == b) return;
    if(szx[a] + szy[a] <= szx[b] + szy[b]) swap(a, b);
    cur_ans -= 1LL * szx[a] * szy[a] + 1LL * szx[b] * szy[b];
    // merge b into a
    where[pt] = &parent[b];
    val[pt++] = parent[b];
    parent[b] = a;
    where[pt] = &szx[a];
    val[pt++] = szx[a];
    szx[a] += szx[b];
    where[pt] = &szy[a];
    val[pt++] = szy[a];
    szy[a] += szy[b];
    cur_ans += 1LL * szx[a] * szy[a];
}

struct Node{
    vpii changes;
    int lo, hi;
    Node* l;
    Node* r;
    Node(int lo, int hi) : lo(lo), hi(hi) {
        int mid = lo + (hi - lo) / 2;
        if(lo + 1 < hi){
            l = new Node(lo, mid);
            r = new Node(mid, hi);
        }
    }

    void add_change(pii p, int L, int R){
        if(L <= lo && hi <= R){
            changes.push_back(p);
            return;
        }
        if(hi <= L || R <= lo){
            return;
        }
        l->add_change(p, L, R);
        r->add_change(p, L, R);
    }

    void dfs(){
        ll old_ans = cur_ans;
        int old_pt = pt;
        for(pii p : changes){
            merge(p.first, A + p.second);
        }
        if(lo + 1 < hi){
            l->dfs();
            r->dfs();
        }else{
            ans[lo] = cur_ans;
        }
        while(pt > old_pt){
            pt--;
            *where[pt] = val[pt];
        }
        cur_ans = old_ans;
    }
};

void solve(){
    int q;
    cin >> q;

    Node* st = new Node(0, q);
    map<pii, int> lst;
    set<pii> exists;
    for(int i = 0; i < q; i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        if(exists.find({x, y}) == exists.end()){
            lst[{x, y}] = i;
            exists.insert({x, y});
        }else{
            st->add_change({x, y}, lst[{x, y}], i);
            exists.erase({x, y});
        }
    }
    for(pii p : exists){
        int x, y;
        tie(x, y) = p;
        st->add_change({x, y}, lst[{x, y}], q);
    }
    ans.resize(q);
    parent.resize(2*A);
    iota(parent.begin(), parent.end(), 0);
    szx.resize(2*A);
    szy.resize(2*A);
    for(int i = 0; i < A; i++){
        szx[i] = 1;
    }
    for(int i = A; i < 2*A; i++){
        szy[i] = 1;
    }

    st->dfs();
    for(ll i : ans){
        cout << i << ' ';
    }
    cout << endl;
    debug(cur_ans);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}