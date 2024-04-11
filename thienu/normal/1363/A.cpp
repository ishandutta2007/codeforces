#include <bits/stdc++.h>

#define u_map unordered_map
#define u_set unordered_set

using ll = long long;

using namespace std;

void solve(){
    int n, x;
    cin >> n >> x;
    int odd = 0;
    int even = 0;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(a & 1){
            odd++;
        }
        else{
            even++;
        }
    }
    if(odd == 0){
        cout << "No" << endl;
    }
    else if(even == 0){
        cout << ((x & 1) ? "Yes" : "No") << endl;
    }
    else if(x == n){
        cout << ((odd & 1) ? "Yes" : "No") << endl;
    }
    else{
        cout << "Yes" << endl;
    }
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}