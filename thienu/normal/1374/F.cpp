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

void swap3(vector<pair<int, int>> &v, int x){
    pair<int, int> tmp = v[x+2];
    v[x+2] = v[x+1];
    v[x+1] = v[x];
    v[x] = tmp;
}

void solve(){
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    vector<int> cnt(501);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v[i] = {x, cnt[x]};
        cnt[x]++;
    }

    if(n == 3){
        int i = 0;
        vector<int> ans;
        while(i < 10 && v[0].first > v[1].first || v[1].first > v[2].first){
            ans.push_back(1);
            swap3(v, 0);
            i++;
            debug(v, i);
        }
        if(i >= 10)
        {
            cout << -1 << endl;
        }
        else{
            cout << ans.size() << endl;
            for(int i : ans) cout << i << " ";
            cout << endl;
        }
        return;
    }

    vector<pair<int, int>> a = v, backup = v;
    sort(a.begin(), a.end());

    vector<int> ans;
    for(int p = 0; p < n-2; p++){
        int cur = distance(v.begin(), find(v.begin(), v.end(), a[p]));
        if((cur - p) % 2 == 1){
            if(cur < n-2){
                swap3(v, cur);
                ans.push_back(cur);
                cur++;
            }
            else if(cur == n-2){
                swap3(v, n-3);
                ans.push_back(n-3);
                cur++;
            }
            else{
                for(int i = 0; i < 2; i++){
                    swap3(v, n-3);
                    ans.push_back(n-3);
                }
                cur--;
            }
        }
        while(cur > p){
            swap3(v, cur-2);
            ans.push_back(cur-2);
            cur-=2;
        }
        // debug(v);
    }

    debug(v);

    bool sorted = true;
    for(int i = 0; i < n-1; i++){
        if(v[i].first > v[i+1].first) sorted = false;
    }

    
    bool parity = false;
    if(sorted){
        goto end;
    }


    // parity

    debug("parity");
    v = backup;
    ans.clear();
    for(int p = 0; p < n-2; p++){
        int cur = distance(v.begin(), find(v.begin(), v.end(), a[p]));
        if((cur - p) % 2 == 1){
            if(cur < n-2){
                swap3(v, cur);
                ans.push_back(cur);
                cur++;
            }
            else if(cur == n-2){
                swap3(v, n-3);
                ans.push_back(n-3);
                cur++;
            }
            else{
                for(int i = 0; i < 2; i++){
                    swap3(v, n-3);
                    ans.push_back(n-3);
                }
                cur--;
            }
        }
        while(cur > p){
            swap3(v, cur-2);
            ans.push_back(cur-2);
            cur-=2;
        }
        // check parity
        if(!parity && p > 0 && v[p].first == v[p-1].first){
            for(int i = 0; i < 2; i++){
                swap3(v, p-1);
                ans.push_back(p-1);
            }
            for(int i = 0; i < 2; i++){
                swap3(v, p);
                ans.push_back(p);
            }
            parity = true;
        }
        // debug(v);
    }
    if(!parity){
        swap3(v, n-3);
        ans.push_back(n-3);
    }

    sorted = true;
    for(int i = 0; i < n-1; i++){
        if(v[i].first > v[i+1].first) sorted = false;
    }

    end:
    if(!sorted){
        cout << -1 << endl;
    }
    else{
        cout << ans.size() << endl;
        for(int i : ans){
            cout << i+1 << " ";
        }
        cout << endl;
    }
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