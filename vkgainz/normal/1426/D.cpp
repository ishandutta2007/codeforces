#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n; cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    ll pref[n+1];
    map<ll,int> lastOccur;
    pref[0] = 0;
    for(int i=1;i<=n;i++) pref[i] = pref[i-1]+a[i-1];
    vector<int> segs[n+1];
    for(int i=0;i<=n;i++){
        if(lastOccur.find(pref[i])!=lastOccur.end()){
            segs[i].push_back(lastOccur[pref[i]]+1);
        }
        lastOccur[pref[i]] = i;
    }
    int ans = 0;
    multiset<int> in;
    for(int i=n;i>=0;i--){
        if(!in.empty() && !segs[i].empty() && i<=*in.rbegin()){
            in.clear();
            ++ans;
        }
        for(int l : segs[i]){
            in.insert(l);
        }
    }
    if(!in.empty()) ++ans;
    cout << ans << endl;
    
}