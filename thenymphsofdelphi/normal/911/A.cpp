#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n;
    cin >> n;
    int a[n];
    int mn1 = 2e9, mn2 = 2e9;
    vector <int> b;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        mn1 = min(mn1, a[i]);
    }
    for (int i = 0; i < n; i++){
        if (a[i] == mn1){
            b.push_back(i);
        }
    }
    for (int i = 1; i < b.size(); i++){
        mn2 = min(mn2, b[i] - b[i - 1]);
    }
    cout << mn2;
}