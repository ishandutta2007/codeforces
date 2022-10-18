#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, ans = 0;
    cin >> n;
    bool ck[1001];
    int a[n];
    vector <int> num;
    for (int i = 0; i < 1001; i++){
        ck[i] = false;
    }
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = n - 1; i >= 0; i--){
        if (!ck[a[i]]){
            ck[a[i]] = true;
            num.insert(num.begin(), a[i]);
            ans++;
        }
    }
    cout << ans << endl;
    for (int i = 0; i < ans; i++){
        cout << num[i] << " ";
    }
}