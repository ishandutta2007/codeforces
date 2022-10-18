#include<bits/stdc++.h>
using namespace std;

int a[1010];

int main(){
    int n, x, sum = 0, mx = 0;
    cin >> n;
    for (int i = 0; i < 1010; i++){
        a[i] = 0;
    }
    for (int i = 0; i < n; i++){
        cin >> x;
        a[x]++;
    }
    for (int i = 0; i < 1010; i++){
        if (a[i] != 0){
            sum++;
            mx = max(mx, a[i]);
        }
    }
    cout << mx << " " << sum;
}