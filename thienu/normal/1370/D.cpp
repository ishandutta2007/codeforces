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

bool ok(int n, const vector<int> &v, int k, int maxi){
    int count = 0;
    bool last = false;
    for(int i = 0; i < n; i++){
        if(last){
            last = false;
            continue;
        }
        if(v[i] <= maxi){
            count++;
            last = true;
        }
    }
    return count >= k;
}

int minimum_subsequence(const vector<int> &v, int k){
    int left = 0;
    int right = 1e9;
    int n = v.size();
    while(left < right){
        int mid = (left + right) / 2;
        if(ok(n, v, k, mid)){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    return left;
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    if(k % 2 == 0){
        int a = minimum_subsequence(vector<int>(v.begin(), v.end()-1), k/2);
        int b = minimum_subsequence(vector<int>(v.begin()+1, v.end()), k/2);
        debug(a, b);
        cout << min(a, b) << endl;
    }
    else{
        int a = minimum_subsequence(vector<int>(v.begin()+1, v.end()-1), k/2);
        int b = minimum_subsequence(vector<int>(v.begin(), v.end()), k/2+1);
        debug(a, b);
        cout << min(a, b) << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}