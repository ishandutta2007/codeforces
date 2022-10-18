#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, idx, x;
    cin >> n >> m;
    int a[n];
    if (m >= 2){
        cout << "Yes";
        return 0;
    }
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (a[i] == 0){
            idx = i;
        }
    }
    cin >> x;
    a[idx] = x;
    for (int i = 1; i < n; i++){
        if (a[i] < a[i - 1]){
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
}