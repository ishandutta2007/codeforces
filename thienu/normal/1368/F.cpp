#include <bits/stdc++.h>

#define u_map unordered_map
#define u_set unordered_set
#define u_multiset unordered_multiset

using ll = long long;

using namespace std;

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
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

void solve(){
    int n;
    cin >> n;

    if(n <= 3){
        cout << 0 << endl;
        exit(0);
    }

    int best_spacing;
    int best_r = 0;
    for(int i = 2; i <= n; i++){
        int gaps = (n-1) / i + 1;
        int r = n - (i-1) - gaps;
        debug(i, r);
        if(r > best_r){
            best_r = r;
            best_spacing = i;
        }
    }
    debug(best_r, best_spacing);

    set<int> important;
    for(int i = 1; i < n; i++){
        if(i % best_spacing != 0){
            important.insert(i);
        }
    }

    vector<int> off;
    for(int i : important){
        off.push_back(i);
    }
    debug(important);
    while(off.size() > best_spacing - 1){
        debug(off);
        int k = off.size();
        cout << k;
        for(int i : off){
            cout << " " << i;
        }
        cout << endl;
        cout.flush();

        int start;
        cin >> start;
        if(start == 0) exit(0);
        off.clear();
        for(int i = 0; i < k; i++){
            int pos = start+i;
            if(pos > n) pos -= n;
            if(important.find(pos) != important.end()){
                off.push_back(pos);
            }
        }
    }
    debug(off);
    cout << 0 << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}