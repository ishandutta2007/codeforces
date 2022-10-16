#include <bits/stdc++.h>

#define u_map unordered_map
#define u_set unordered_set

using ll = long long;

using namespace std;

void solve(vector<ll> vals){
    ll n;
    cin >> n;
    int i = 0;
    ll ans = 0;
    while(n > 0){
        if(n & 1){
            // cout << vals[i] << endl;
            ans += vals[i];
        }
        n >>= 1;
        // cout << n << " " << i<< endl;
        i++;
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    vector<ll> vals(61);
    vals[0] = 1;
    for(int i = 1; i < 61; i++){
        vals[i] = 2 * vals[i-1] + 1;
    }
    while(tc--){
        solve(vals);
    }
    return 0;
}