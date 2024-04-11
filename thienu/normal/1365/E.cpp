#include <bits/stdc++.h>

#define u_map unordered_map
#define u_set unordered_set

using ll = long long;

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<ll> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    if(n >= 3){
        ll maxi = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                for(int k = j+1; k < n; k++){
                    maxi = max(maxi, v[i]|v[j]|v[k]);
                }
            }
        }
        cout << maxi << endl;
    }
    else{
        ll ans = 0;
        for(ll i : v){
            ans |= i;
        }
        cout << ans << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}