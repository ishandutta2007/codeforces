#include <bits/stdc++.h>

#define u_map unordered_map
#define u_set unordered_set
#define u_multiset unordered_multiset

using ll = long long;

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }

    if(n & 1){
        if(a[n/2] != b[n/2]){
            cout << "No" << endl;
            return;
        }
    }

    map<pair<int, int>, int> pairs;
    for(int i = 0; i < n/2; i++){
        pairs[minmax(a[i], a[n-i-1])]++;

        // auto p = minmax(a[i], a[n-i-1]);
        // cout << p.first << " " << p.second << endl;
    }

    for(int i = 0; i < n/2; i++){
        auto to_find = minmax(b[i], b[n-i-1]);
        if(pairs[to_find] == 0){
            // cout << to_find.first << " " << to_find.second << endl;
            cout << "No" << endl;
            return;
        }
        pairs[to_find]--;
    }
    cout << "Yes" << endl;
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