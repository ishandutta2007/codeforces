#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    int t = max(a[0], b[0]);
    for (int i = 1; i < n; i++){
        if (a[i] <= t && b[i] <= t){
            t = max(a[i], b[i]);
        }
        else if (a[i] > t && b[i] <= t){
            t = b[i];
        }
        else if (a[i] <= t && b[i] > t){
            t = a[i];
        }
        else{
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}