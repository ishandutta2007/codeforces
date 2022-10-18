#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n;
    cin >> n;
    int x, b[n], sum = 0;
    for (int i = 0; i < n; i++){
        cin >> x;
        sum += x;
    }
    for (int i = 0; i < n; i++){
        cin >> b[i];
    }
    sort(b, b + n);
    if (sum <= b[n - 1] + b[n - 2]){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}