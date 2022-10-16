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
#ifdef DEBUG
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

void solve(){
    string s;
    cin >> s;
    int n = s.size();

    list<pair<char, int>> seq;
    char cur = s[0];
    int cnt = 0;
    for(char c : s){
        if(cur != c){
            seq.push_back({cur, cnt});
            cur = c;
            cnt = 0;
        }
        cnt++;
    }
    seq.push_back({cur, cnt});

    debug(seq);

    int ans = 0;
    while(seq.size() > 1){
        // sweep
        for(auto it = seq.begin(); it != seq.end();){
            char c = it->first;
            int times = it->second;
            if(it == seq.begin() || next(it) == seq.end()){
                times -= 1;
            }
            else{
                times -= 2;
            }
            it = seq.erase(it);
            it = seq.insert(it, {c, times});
            it++;
        }
        // delete
        for(auto it = seq.begin(); it != seq.end();){
            if(it->second <= 0) it = seq.erase(it);
            else it++;
        }
        ans++;
        if(seq.size() <= 1) break;
        // merge
        for(auto it = seq.begin(); next(it) != seq.end();){
            if(it->first == next(it)->first){
                int times = it->second + next(it)->second;
                int chr = it->first;
                it = seq.erase(it);
                it = seq.erase(it);
                it = seq.insert(it, {chr, times});
            }
            else{
                it++;
            }
        }
        debug(seq);
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}