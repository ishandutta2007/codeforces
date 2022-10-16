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

void solve(){
    int n;
    cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    vpii runs;
    int run_start = v[0];
    int last = v[0];
    for(int i = 1; i < n; i++){
        if(v[i] != last + 1){
            runs.push_back({run_start, v[i-1]});
            run_start = v[i];
        }
        last = v[i];
    }
    runs.push_back({run_start, v[n-1]});
    debug(runs);
    vvi ans;
    while(runs.size() > 1){
        // look for inversions
        for(int i = 0; i < runs.size(); i++){
            for(int j = i + 1; j < runs.size(); j++){
                if(runs[i].first == runs[j].second + 1){
                    debug(i, j);
                    // swap i and j
                    vi sizes(4);
                    vpii new_runs;
                    for(int k = j + 1; k < runs.size(); k++){
                        new_runs.push_back(runs[k]);
                        sizes[3] += runs[k].second - runs[k].first + 1;
                    }
                    new_runs.push_back(runs[j]);
                    sizes[2] += runs[j].second - runs[j].first + 1;
                    for(int k = i; k < j; k++){
                        new_runs.push_back(runs[k]);
                        sizes[1] += runs[k].second - runs[k].first + 1;
                    }
                    for(int k = 0; k < i; k++){
                        new_runs.push_back(runs[k]);
                        sizes[0] += runs[k].second - runs[k].first + 1;
                    }

                    vpii nn_runs;
                    for(int i = 0; i < new_runs.size(); i++){
                        int start = new_runs[i].first;
                        int end = new_runs[i].second;
                        while(i + 1 < new_runs.size() && new_runs[i].second + 1 == new_runs[i+1].first){
                            i++;
                            end = new_runs[i].second;
                        }
                        nn_runs.push_back({start, end});
                    }
                    runs = nn_runs;

                    vi new_sizes;
                    for(int i : sizes){
                        if(i) new_sizes.push_back(i);
                    }

                    ans.push_back(new_sizes);
                    debug(runs);

                }
            }
        }
    }

    cout << ans.size() << endl;
    for(vi a : ans){
        cout << a.size() << " ";
        for(int i : a){
            cout << i << " ";
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