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

struct Node{
    int lo, hi;
    ll val, madd = 0;
    Node *l = 0, *r = 0;

    void update(){
        val = l->val + r->val;
    }

    Node(int lo, int hi, vll &v) : lo(lo), hi(hi) {
        if(lo + 1 < hi){
            int mid = lo + (hi - lo) / 2;
            l = new Node(lo, mid, v);
            r = new Node(mid, hi, v);
            update();
        }else{
            val = v[lo];
        }
    }
    
    void add(int L, int R, ll num){
        if(R <= lo || hi <= L) return;
        if(L <= lo && hi <= R){
            val += 1LL * num * (hi-lo);
            madd += num;
            return;
        }
        push();
        l->add(L, R, num);
        r->add(L, R, num);
        update();
    }

    ll query(int L, int R){
        if(R <= lo || hi <= L) return 0;
        if(L <= lo && hi <= R){
            return val;
        }
        push();
        return l->query(L, R) + r->query(L, R);
    }

    void push(){
        if(madd != 0){
            l->add(lo, hi, madd);
            r->add(lo, hi, madd);
            madd = 0;
        }
    }
};

void add_cut(int cut, set<int> &cuts, Node* st){
    if(cuts.find(cut) != cuts.end()) return;
    auto it = cuts.upper_bound(cut);
    int bef = *prev(it);
    int aft = *it;
    st->add(cut, aft, -(cut - bef));
    cuts.insert(cut);
}

void remove_cut(int cut, set<int> &cuts, Node* st){
    if(cuts.find(cut) == cuts.end()) return;
    cuts.erase(cut);
    auto it = cuts.upper_bound(cut);
    int bef = *prev(it);
    int aft = *it;
    st->add(cut, aft, cut - bef);
}

void solve(){
    int n, q;
    cin >> n >> q;
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    vll run(n, 1);
    set<int> cuts;
    cuts.insert(0);
    for(int i = 1; i < n; i++){
        if(v[i-1] <= v[i]){
            run[i] = run[i-1] + 1;
        }else{
            cuts.insert(i);
        }
    }
    cuts.insert(n);
    Node* st = new Node(0, n, run);
    debug(cuts, run);

    while(q--){
        debug(cuts);
        int t;
        cin >> t;
        if(t == 1){
            int idx, num;
            cin >> idx >> num;
            idx--;
            v[idx] = num;
            if(idx > 0){
                if(v[idx-1] <= v[idx]){
                    remove_cut(idx, cuts, st);
                }else{
                    add_cut(idx, cuts, st);
                }
            }
            if(idx < n-1){
                if(v[idx] <= v[idx+1]){
                    remove_cut(idx+1, cuts, st);
                }else{
                    add_cut(idx+1, cuts, st);
                }
            }
        }else{
            int l, r;
            cin >> l >> r;
            l--;
            // first cut after l
            int first = *cuts.upper_bound(l);
            if(first >= r){
                cout << 1LL * (r-l) * (r-l+1) / 2 << endl;
            }else{
                cout << 1LL * (first-l) * (first-l+1) / 2 + st->query(first, r) << endl;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}