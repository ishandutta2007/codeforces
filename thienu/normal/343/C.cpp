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

int n, m;

ll dist(ll pos, ll left, ll right){
    ll a = pos - left;
    ll b = right - pos;
    return max(a, b) + min(a, b) * 2;
}

bool possible(ll time, vector<ll> &heads, vector<ll> &tracks){
    int head = 0;
    int track = 0;
    for(int head = 0; head < n; head++){
        // debug(head, track);
        ll pos = heads[head];
        if(pos - tracks[track] > time) return false;
        ll left = min(pos, tracks[track]);
        while(track < m && tracks[track] <= pos){
            track++;
        }
        while(track < m){
            if(dist(pos, left, tracks[track]) <= time){
                track++;
            }
            else{
                break;
            }
        }
        // debug(head, track);
        if(track == m){
            return true;
        }
    }
    return false;
}

void solve(){
    cin >> n >> m;
    vector<ll> heads(n);
    vector<ll> tracks(m);
    for(int i = 0; i < n; i++) cin >> heads[i];
    for(int i = 0; i < m; i++) cin >> tracks[i];

    // debug(possible(10000000000, heads, tracks));

    ll left = 0;
    ll right = 4e10;
    while(left < right){
        ll mid = (left + right) / 2LL;
        if(possible(mid, heads, tracks)){
            debug(mid, possible(mid, heads, tracks));
            right = mid;
        }
        else{
            debug(mid, possible(mid, heads, tracks));
            left = mid + 1;
        }
    }
    cout << left << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}