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


// upsolved
void solve(){
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v[i] = make_pair(x, i);
    }

    vector<pair<int, int>> sorted = v;
    sort(sorted.begin(), sorted.end());

    vector<int> perm(n);
    vector<int> pos(n);
    for(int i = 0; i < n; i++){
        perm[i] = distance(sorted.begin(), find(sorted.begin(), sorted.end(), v[i]));
        pos[perm[i]] = i;
    }
    debug(perm, pos);

    vector<pair<int, int>> ans;

    // handle index i
    for(int i = n-1; i >= 0; i--){
        // 0 4 3 2 1
        // 0 3 2 1 4
        vector<pair<int, int>> ind;
        for(int j = 0; j < i; j++){
            if(perm[j] > perm[i] /*&& v[j].first > v[i].first*/){
                ind.push_back(make_pair(perm[j], j));
            }
        }
        sort(ind.begin(), ind.end());
        debug(ind);
        for(auto &p : ind){
            // cout << p.second + 1 << " " << i + 1 << endl;
            ans.push_back(make_pair(p.second, i));
            swap(perm[p.second], perm[i]);
            swap(pos[perm[p.second]], pos[perm[i]]);
            // swap(v[p.second], v[i]);
        }
        debug(perm, pos, v);
    }

    cout << ans.size() << endl;
    for(auto &p : ans){
        if(v[p.first].first > v[p.second].first){
            cout << p.first + 1 << " " << p.second + 1 << endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

// 2 2 1 1
// 1 2 1 2
// 1 2 1 2
// 1 2 1 2
// 1 1 2 2