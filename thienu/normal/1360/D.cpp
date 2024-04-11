#include <bits/stdc++.h>

#define u_map unordered_map
#define u_set unordered_set

using ll = long long;

using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    int limit = (int) sqrt(n) + 2;
    int maxi = 0;
    for(int i = 1; i < limit; i++){
        if(n % i == 0){
            if(i <= k){
                maxi = max(i, maxi);
            }
            if(n/i <= k){
                maxi = max(n/i, maxi);
            }
        }
    }
    cout << n/maxi << endl;
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}