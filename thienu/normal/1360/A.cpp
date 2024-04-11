#include <bits/stdc++.h>

#define u_map unordered_map
#define u_set unordered_set

using ll = long long;

using namespace std;

void solve(){
    int a, b;
    cin >> a >> b;
    cout << min(max(2*a, b), max(a, 2*b)) * min(max(2*a, b), max(a, 2*b)) << endl;
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}