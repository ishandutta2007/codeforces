#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    if (n % 2 == 1){
        cout << "NO";
        return 0;
    }
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    if (a[0] == a[n / 2 - 1] && a[n / 2] == a[n - 1] && a[0] != a[n - 1]){
        cout << "YES\n";
        cout << a[0] << " " << a[n - 1];
        return 0;
    }
    cout << "NO";
}