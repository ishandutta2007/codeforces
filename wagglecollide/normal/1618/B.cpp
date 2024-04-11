
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<string> v(n - 2);
    for(int i = 0; i < n - 2; i++) cin >> v[i];
    string ans;
    for(int i = 0; i < n - 2; i++){
        if(ans.empty() || ans.back() != v[i][0]){
            ans += v[i];
        }else{
            ans += v[i].back();
        }
    }
    string s;
    for(int i = 0; i < n - 2; i++){
        string now = "";
        now += v[i][0];
        now += v[i].back();
        if(s == now) continue;

        string tmp = ans;
        tmp.pop_back();
        tmp.pop_back();
        tmp += v[i];
        s = tmp;
    }
    ans += s;
    for(int i = 0; i < n; i++) cout << ans[i];
    cout << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}