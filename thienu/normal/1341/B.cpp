//https://codeforces.com/contest/1341/problem/B
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <algorithm>

using ll = long long;

using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> heights;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        heights.push_back(x);
    }
    vector<bool> is_peak(n, false);
    for(int i = 1; i < n-1; i++){
        is_peak[i] = heights[i] > heights[i-1] && heights[i] > heights[i+1];
    }
    vector<int> pref;
    pref.push_back(0);
    for(int i = 1; i < n; i++){
        pref.push_back(pref[i-1] + (is_peak[i] ? 1 : 0));
    }
    
    // for(bool i : is_peak){
    //     cout << (i ? 1 : 0) << " ";
    // }
    // cout << endl;
    // for(int i : pref){
    //     cout << i << " ";
    // }
    // cout << endl;

    int maxi = -1;
    int maxindex = 0;
    for(int i = 1; i <= n-k+1; i++){
        int val = pref[i+k-3]-pref[i-1];
        if(val > maxi){
            maxi = val;
            maxindex = i;
        }
    }
    cout << maxi + 1 << " " << maxindex << endl;
}

int main(){
    int tc;
    cin >> tc;
    for(int i = 0; i < tc; i++){
        solve();
    }
    return 0;
}