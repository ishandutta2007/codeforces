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

const int L = 20;

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    vi p(n + L);
    for(int i = 1; i < n; i++){
        int j = p[i-1];
        while(j > 0 && s[i] != s[j]){
            j = p[j-1];
        }
        if(s[i] == s[j]){
            j++;
        }
        p[i] = j;
    }
    debug(p);
    int q;
    cin >> q;
    vector<pair<string, int>> queries;
    for(int i = 0; i < q; i++){
        string t;
        cin >> t;
        queries.push_back(make_pair(t, i));
    }
    sort(queries.begin(), queries.end());
    debug(queries);
    vvi ans(q);
    for(int c = 0; c < q; c++){
        string t = queries[c].first;
        int lcp = 0;
        if(c > 0){
            while(lcp < t.size() && lcp < queries[c-1].first.size() && t[lcp] == queries[c-1].first[lcp]){
                lcp++;
            }
        }
        debug(lcp);
        int m = t.size();
        for(int i = n+lcp; i < n+m; i++){
            debug(i);
            int j = p[i-1];
            while(j > 0 && t[i-n] != (j >= n ? t[j-n] : s[j])){
                j = p[j-1];
            }
            debug(j);
            if(t[i-n] == (j >= n ? t[j-n] : s[j])){
                j++;
            }
            p[i] = j;
        }
        vi pf;
        for(int i = 0; i < m; i++){
            pf.push_back(p[n+i]);
        }
        ans[queries[c].second] = pf;
    }
    for(vi v : ans){
        for(int i : v){
            cout << i << ' ';
        }
        cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}