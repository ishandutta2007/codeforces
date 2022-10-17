#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

set<ll> s;
void solve(vector<ll> arr){
    ll tot=0, mn=arr[0], mx=arr[0], mid; 
    for (int i=0;i<arr.size();++i) tot+=arr[i], mn=min(mn,arr[i]), mx=max(mx,arr[i]);
    s.insert(tot);
    mid=mn+mx>>1;
    vector<ll> l, r;
    for (int i=0;i<arr.size();++i){
        if (arr[i]<=mid) l.push_back(arr[i]);
        else r.push_back(arr[i]);
    }
    if (l.empty()||r.empty()) return;
    solve(l), solve(r);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n, q; cin >> n >> q;
        vector<ll> arr(n);
        s.clear();
        for (int i=0;i<n;++i) cin >> arr[i];
        solve(arr);
        while (q--){
            ll v; cin >> v;
            cout << (s.count(v)?"Yes":"No") << '\n';
        }
    }
}