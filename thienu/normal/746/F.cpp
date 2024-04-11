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
    int n, w, k;
    cin >> n >> w >> k;
    vector<int> a(n), t(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> t[i];

    multiset<int> full;
    multiset<int> partial;

    int right = 0;
    int pleasure = 0;
    int time = 0;

    int ans = 0;

    for(int left = 0; left < n; left++){
        right = max(right, left);
        while(right < n){
            // simulate adding t[right]
            int new_time = time;
            if(partial.size() < w){
                new_time += (t[right] + 1) / 2;
            }
            else if(t[right] > *partial.begin()){
                new_time += (t[right] + 1) / 2 + *partial.begin() - (*partial.begin() + 1) / 2;
            }
            else{
                new_time += t[right];
            }
            if(new_time <= k){
                time = new_time;
                if(partial.size() < w){
                    partial.insert(t[right]);
                }
                else{
                    partial.insert(t[right]);
                    int x = *partial.begin();
                    partial.erase(partial.begin());
                    full.insert(x);
                }
                pleasure += a[right];
                right++;
            }
            else{
                break;
            }
        }


        debug(left, right, full, partial, pleasure);
        ans = max(ans, pleasure);

        // erase left
        if(left < right){
            pleasure -= a[left];
            if(partial.find(t[left]) != partial.end()){
                debug("erase partial", t[left]);
                partial.erase(partial.find(t[left]));
                time -= (t[left] + 1) / 2;
                if(full.size() > 0){
                    int x = *prev(full.end());
                    full.erase(prev(full.end()));
                    time -= x;
                    time += (x + 1) / 2;
                    partial.insert(x);
                }
            }
            else{
                debug("erase full", t[left]);
                time -= t[left];
                full.erase(full.lower_bound(t[left]));
            }
        }
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}