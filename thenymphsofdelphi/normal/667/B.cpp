#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, s = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n - 1; i++){
        s += a[i];
    }
    cout << a[n - 1] - s + 1;
}