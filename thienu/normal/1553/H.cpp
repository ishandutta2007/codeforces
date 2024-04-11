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

const int INF = 1e9 + 7;

struct Node{
    int layer, mini = INF, maxi = -INF, ans = INF;
    Node* l = 0;
    Node* r = 0;
    Node(int la) : layer(la) {};

    void recalc(){
        assert(l != 0 && r != 0);
        mini = min(l->mini, (1<<(layer-1))+r->mini);
        maxi = max(l->maxi, (1<<(layer-1))+r->maxi);
        ans = min({l->ans, r->ans, (1<<(layer-1))+r->mini-l->maxi});
    }

    void init(vi &v, int cur){
        if(layer == 0){
            if(v[cur]){
                maxi = 0;
                mini = 0;
            }
        }else{
            l = new Node(layer-1);
            l->init(v, cur);
            r = new Node(layer-1);
            r->init(v, cur+(1<<(layer-1)));
            recalc();
        }
    }

    void swap_children(){
        assert(l != 0 && r != 0);
        swap(l, r);
        recalc();
    }

    void swap_layer(int la){
        if(layer == la){
            swap_children();
        }else{
            l->swap_layer(la);
            r->swap_layer(la);
            recalc();
        }
    }
};

void solve(){
    int n, k;
    cin >> n >> k;
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    int m = (1<<k);
    vi ok(m);
    for(int i = 0; i < n; i++){
        ok[v[i]] = 1;
    }
    Node* root = new Node(k);
    root->init(ok, 0);

    vi code = {k-1};
    for(int i = k-2; i >= 0; i--){
        int sz = code.size();
        code.push_back(i);
        for(int j = 0; j < sz; j++){
            code.push_back(code[j]);
        }
    }
    debug(code);

    vi ans(m);
    int cur = 0;
    for(int i = 0; i < m; i++){
        ans[cur] = root->ans;
        if(i < m-1){
            cur ^= (1<<code[i]);
            root->swap_layer(code[i]+1);
        }
    }
    for(int i : ans){
        cout << i << ' ';
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}