#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n;
    cin >> n;
    int a[n], s = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        s += a[i];
    }
    if (s % n){
        cout << 0;
        return 0;
    }
    vector <int> b;
    for (int i = 0; i < n; i++){
        if (a[i] == s / n){
            b.push_back(i + 1);
        }
    }
    cout << b.size();
    if (b.size() == 0){
        return 0;
    }
    cout << endl;
    for (int i = 0; i < b.size(); i++){
        cout << b[i] << ' ';
    }
}