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

void solve(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, set<int>>> tbox(n);
    int total = 0;
    for(int i = 0; i < n; i++){
        int l;
        cin >> l;
        set<int> es;
        tbox[i] = {i, es};
        for(int j = 0; j < l; j++){
            int x;
            cin >> x;
            x--;
            tbox[i].second.insert(x);
        }
        total += l;
    }
    sort(tbox.begin(), tbox.end(), [&](pair<int, set<int>> &a, pair<int, set<int>> &b) {return a.second.size() < b.second.size();});
    debug(tbox);
    vector<set<int>> box;
    for(auto p : tbox){
        box.push_back(p.second);
    }
    vi desired(n);
    int base = total / n;
    int extra = total % n;
    for(int i = 0; i < n; i++){
        if(i < extra) desired[i] = base+1;
        else desired[i] = base;
    }
    reverse(desired.begin(), desired.end());

    vector<pair<pii, int>> ans;
    stack<int> changes;
    debug(desired);

    int p1 = 0, p2 = n-1;
    while(p1 < p2){
        debug(p1, p2, box);
        if(desired[p1] == box[p1].size()){
            p1++;
            continue;
        }
        if(desired[p2] == box[p2].size()){
            p2--;
            continue;
        }
        int d1 = desired[p1] - box[p1].size();
        int d2 = box[p2].size() - desired[p2];
        assert(d1 > 0);
        assert(d2 > 0);
        int trans = min(d1, d2);
        for(int i : box[p1]){
            if(box[p2].find(i) != box[p2].end()){
                changes.push(i);
                box[p2].erase(i);
            }
        }
        debug(changes.size());
        for(int i = 0; i < trans; i++){
            int x = *box[p2].begin();
            debug(x);
            ans.push_back({{tbox[p2].first+1, tbox[p1].first+1}, x+1});
            box[p1].insert(x);
            box[p2].erase(x);
        }
        while(!changes.empty()){
            box[p2].insert(changes.top());
            changes.pop();
        }
    }
    cout << ans.size() << endl;
    debug(ans);
    for(auto p : ans){
        cout << p.first.first << ' ' << p.first.second << ' ' << p.second << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}