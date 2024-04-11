#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int dig[n];
    for(int i=0;i<n;i++){
        dig[i] = s[i]-'0'-1;
    }
    int pref[n+1];
    pref[0] = 0;
    for(int i=1;i<=n;i++){
        pref[i] = pref[i-1]+dig[i-1];
    }
    map<int,int> freq;
    for(int i=0;i<=n;i++){
        freq[pref[i]]++;
    }
    ll ans = 0;
    for(auto &it : freq){
        ans+=(ll) (it.second)*(it.second-1)/2;
    }
    cout << ans << endl;
}
int main(){
    int t; cin >> t;
    while(t--) solve();
}