#include <bits/stdc++.h>
using namespace std;

#define ll long long
void solve(){
    int n; cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    pair<int,int> ans = {-1,-1};
    for(int i=0;i<n-1;i++){
        if(abs(a[i]-a[i+1]) >=2)
            ans = {i,i+1};
    }
    if(ans==make_pair(-1,-1))
        cout << "NO" << endl;
    else
        cout << "YES" << " " << ans.first+1 << " " << ans.second+1 << endl;
}
int main(){
    int t; cin >> t;
    while(t--) solve();
}