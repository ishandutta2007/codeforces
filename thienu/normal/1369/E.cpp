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
    int n, m;
    cin >> n >> m;
    vector<int> amt(n);
    for(int i = 0; i < n; i++){
        cin >> amt[i];
    }
    vector<vector<pair<int, int>>> food(n, vector<pair<int, int>>());
    vector<int> sum(n, 0);
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--;y--;
        sum[x]++;
        sum[y]++;
        food[x].push_back({i, y});
        food[y].push_back({i, x});
    }
    set<int> used_people;
    set<int> used_food;

    debug(food, sum, amt);

    queue<int> q;
    for(int i = 0; i < n; i++){
        if(sum[i] <= amt[i]){
            q.push(i);
            used_food.insert(i);
            debug(i);
        }
    }

    vector<int> ans;

    while(q.size()){
        int f = q.front();
        q.pop();
        for(pair<int, int> p : food[f]){
            if(used_people.find(p.first) == used_people.end()){
                ans.push_back(p.first);
                sum[p.second]--;
                debug(sum);
                if(sum[p.second] <= amt[p.second] && used_food.find(p.second) == used_food.end()){
                    q.push(p.second);
                    used_food.insert(p.second);
                }
                used_people.insert(p.first);
            }
        }
    }

    debug(ans);

    if(ans.size() < m){
        cout << "DEAD" << endl;
    }
    else{
        reverse(ans.begin(), ans.end());
        cout << "ALIVE" << endl;
        for(int i : ans){
            cout << i+1 << " ";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}