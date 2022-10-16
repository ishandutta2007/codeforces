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

vvi items;
int n;
vi best;

struct Node{
    int len, pts;
    map<int, Node*> nxt;
    vi cur;
    Node(int len, int pts, vi &cur) : len(len), pts(pts), cur(cur){

    }

    void path(vi s){
        if(len == n) return;
        Node* n;
        if(nxt.find(s[len]) == nxt.end()){
            vi ncur = cur;
            ncur.push_back(s[len]);
            n = new Node(len+1, pts + items[len][s[len]], ncur);
            nxt[s[len]] = n;
        }else{
            n = nxt[s[len]];
        }
        n->path(s);
    }

    pair<int, vi> dfs(){
        debug(len);
        if(len == n) return {0, {}};
        int ans = 0;
        vi good;
        debug(items, best);
        for(int i = items[len].size()-1; i >= 0; i--){
            if(nxt.find(i) == nxt.end()){
                ans = pts + items[len][i] + best[len+1];
                good = cur;
                good.push_back(i);
                for(int j = len+1; j < n; j++){
                    good.push_back(items[j].size()-1);
                }
                break;
            }
        }
        debug(ans);
        for(pair<int, Node*> p : nxt){
            auto res = p.second->dfs();
            if(res.first > ans){
                ans = res.first;
                good = res.second;
            }
        }
        return {ans, good};
    }
};

void solve(){
    cin >> n;
    items.resize(n);
    for(int i = 0; i < n; i++){
        int l;
        cin >> l;
        for(int j = 0; j < l; j++){
            int x;
            cin >> x;
            items[i].push_back(x);
        }
    }
    vi emp = {};
    Node* root = new Node(0, 0, emp);
    int m;
    cin >> m;
    while(m--){
        vi s(n);
        for(int i = 0; i < n; i++){
            cin >> s[i];
            s[i]--;
        }
        root->path(s);
    }

    // best if start at i
    best.resize(n+1);
    for(int i = n-1; i >= 0; i--){
        best[i] = best[i+1] + items[i][items[i].size()-1];
    }
    debug(best);

    vi res = root->dfs().second;
    for(int i : res){
        cout << i+1 << ' ';
    }
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}