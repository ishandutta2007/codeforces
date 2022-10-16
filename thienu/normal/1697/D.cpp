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

char query_1(int i){
    cout << "? 1 " << i + 1 << endl;
    char c;
    cin >> c;
    return c;
}

// [l, r)
int query_2(int l, int r){
    cout << "? 2 " << l+1 << ' ' << r << endl;
    int x;
    cin >> x;
    return x;
}

void solve(){
    int n;
    cin >> n;
    vector<char> c(n);
    c[0] = query_1(0);
    debug(c);
    for(int i = 1; i < n; i++){
        // figure out what i is
        vi last_occ;
        vector<char> chars;
        vi seen(26);
        for(int j = i-1; j >= 0; j--){
            if(seen[c[j]-'a']) continue;
            seen[c[j]-'a'] = 1;
            last_occ.push_back(j);
            chars.push_back(c[j]);
        }
        debug(i, last_occ, chars);

        int x = query_2(0, i+1);
        if(x > chars.size()){
            c[i] = query_1(i);
        }else{
            // binary search
            int l = 0;
            int r = last_occ.size();
            // letter is inside [l, r)
            while(l + 1 < r){
                debug(l, r);
                int mid = l + (r - l - 1) / 2;
                int result = query_2(last_occ[mid], i+1);
                debug(mid, last_occ.size() - mid);
                if(result > mid+1){
                    l = mid+1;
                }else{
                    r = mid+1;
                }
            }
            debug(l, r);
            c[i] = chars[l];
        }
    }
    cout << "! ";
    for(int i = 0; i < n; i++){
        cout << c[i];
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}