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
    vector<int> events;
    
    for(int i = 0; i < 2 * n; i++){
        char c;
        cin >> c;
        if(c == '-'){
            int x;
            cin >> x;
            events.push_back(x);
        }
        else{
            events.push_back(-1);
        }
    }

    reverse(events.begin(), events.end());

    set<int> used;
    vector<int> ans;

    for(int i = 0; i < 2 * n; i++){
        if(events[i] == -1){
            if(used.empty()){
                cout << "NO" << endl;
                return;
            }
            ans.push_back(*used.begin());
            used.erase(used.begin());
        }
        else{
            used.insert(events[i]);
        }
    }

    reverse(ans.begin(), ans.end());
    reverse(events.begin(), events.end());

    // check
    set<int> s;
    int ptr = 0;
    for(int i = 0; i < 2 * n; i++){
        if(events[i] == -1){
            s.insert(ans[ptr]);
            ptr++;
        }
        else{
            if(s.empty() || *s.begin() != events[i]){
                cout << "NO" << endl;
                return;
            }
            s.erase(s.begin());
        }
    }

    cout << "YES" << endl;
    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}