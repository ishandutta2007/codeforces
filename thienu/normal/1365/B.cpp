// After contest - looked at editorial

#include <bits/stdc++.h>

#define u_map unordered_map
#define u_set unordered_set

using ll = long long;

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> types(n);
    bool has1 = false;
    bool has0 = false;
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    for(int i = 0; i < n; i++){
        cin >> types[i];
        if(types[i] == 1){
            has1 = true;
        }
        else{
            has0 = true;
        }
    }
    bool sorted = true;
    for(int i = 0; i < n-1; i++){
        if(v[i] > v[i+1]){
            sorted = false;
        }
    }
    if(sorted){
        cout << "Yes" << endl;
    }
    else if(has1 && has0){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
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