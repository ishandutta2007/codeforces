#include <bits/stdc++.h>

#define u_map unordered_map
#define u_set unordered_set

using ll = long long;

using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<vector<int>> subsets;
    for(int i = 0; i < k; i++){
        int x;
        cin >> x;
        vector<int> subset(x);
        for(int i = 0; i < x; i++){
            cin >> subset[i];
        }
        subsets.push_back(subset);
    }

    cout << "? " << n;
    for(int i = 1; i <= n; i++){
        cout << " " << i;
    }
    cout << endl;
    cout.flush();

    int maxi;
    cin >> maxi;

    int left = 1;
    int right = n;
    while(left < right){
        int mid = (left + right) / 2;
        cout << "? " << mid - left + 1;
        for(int i = left; i <= mid; i++){
            cout << " " << i;
        }
        cout << endl;
        cout.flush();
        int x;
        cin >> x;
        if(x == maxi){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }

    vector<int> ans(k);
    for(int i = 0; i < k; i++){
        if(find(subsets[i].begin(), subsets[i].end(), left) != subsets[i].end()){
            cout << "? " << n - subsets[i].size();
            for(int j = 1; j <= n; j++){
                if(find(subsets[i].begin(), subsets[i].end(), j) == subsets[i].end()){
                    cout << " " << j;
                }
            }
            cout << endl;
            cout.flush();
            cin >> ans[i];
        }
        else{
            ans[i] = maxi;
        }
    }

    cout << "!";
    for(int i : ans){
        cout << " " << i;
    }
    cout << endl;
    cout.flush();

    string verdict;
    cin >> verdict;
    if(verdict == "Incorrect"){
        exit(0);
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