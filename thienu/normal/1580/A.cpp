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
    vvi grid(n, vi(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c;
            cin >> c;
            grid[i][j] = (c == '1');
        }
    }

    int ans = 1e9;
    vi edge(m), body(m);
    for(int top = 0; top+4 < n; top++){
        fill(edge.begin(), edge.end(), 0);
        fill(body.begin(), body.end(), 0);
        for(int j = 0; j < m; j++){
            for(int i = top + 1; i+1 <= top+3; i++){
                if(!grid[i][j]) edge[j]++;
                if(grid[i][j]) body[j]++;
            }
            if(!grid[top][j]) body[j]++;
            if(!grid[top+3][j]) body[j]++;
        }
        for(int bot = top + 4; bot < n; bot++){
            for(int j = 0; j < m; j++){
                if(grid[bot-1][j]){
                    body[j] += 1;
                }else{
                    body[j] -= 1;
                    edge[j] += 1;
                }
                if(!grid[bot][j]) body[j]++;
            }
            debug(top, bot, edge, body);
            deque<pii> costs;
            int run = 0;
            for(int j = 0; j < m; j++){
                int nc = run + edge[j];
                while(!costs.empty() && costs.front().first >= nc){
                    costs.pop_front();
                }
                costs.push_front({nc, j});
                run += body[j];
            }

            run = 0;
            for(int j = 0; j < m; j++){
                run += body[j];
                while(!costs.empty() && (costs.back().second < j+3)) costs.pop_back();
                if(costs.empty()) break;
                ans = min(ans, costs.back().first - run + edge[j]);
            }
        }
    }
    cout << ans << endl;
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