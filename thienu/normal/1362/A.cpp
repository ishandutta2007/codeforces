#include <bits/stdc++.h>

#define u_map unordered_map
#define u_set unordered_set

using ll = long long;

using namespace std;

void solve(){
    ll a, b;
    cin >> a >> b;
    if(a > b){
        swap(a, b);
    }
    int cnt = 0;
    while (a < b){
        a *= 2;
        cnt++;
    }
    if(a == b){
        cout << (cnt+2) / 3 << endl;
    }
    else{
        cout << -1 << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}