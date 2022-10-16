#include <bits/stdc++.h>

#define u_map unordered_map
#define u_set unordered_set

using ll = long long;

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    int even = 0;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        if(v[i] % 2 == 0){
            even++;
        }
    }
    if(even % 2 == 0){
        cout << "YES" << endl;
    }
    else{
        sort(v.begin(), v.end());
        bool ok = false;
        for(int i = 1; i < n; i++){
            if(v[i] - v[i - 1] == 1){
                ok = true;
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
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