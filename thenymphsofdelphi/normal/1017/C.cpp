#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    int l = sqrt(n), r = n % l, m = n / l;
    int idx = n - r, cnt = 1;
    while (idx < n){
        a[idx] = cnt;
        cnt++;
        idx++;
    }
    for (int i = 1; i <= m; i++){
        idx = n - r - l * i;
        for (int j = 0; j < l; j++){
            a[idx] = cnt;
            cnt++;
            idx++;
        }
    }
    for (int i = 0; i < n; i++){
        cout << a[i] << ' ';
    }
}