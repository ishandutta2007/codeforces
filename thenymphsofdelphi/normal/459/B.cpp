#include<bits/stdc++.h>
using namespace std;
#define min(a, b) ((a < b) ? (a) : (b))
#define max(a, b) ((a > b) ? (a) : (b))

int a[200000];

int main(){
    long long n, mn = 1000000001, mx = -1, cntmn = 0, cntmx = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }
    cout << mx - mn << " ";
    for (int i = 0; i < n; i++){
        if (a[i] == mn){
            cntmn++;
        }
        else if (a[i] == mx){
            cntmx++;
        }
    }
    if (mx - mn == 0){
        cout << cntmn * (cntmn - 1) / 2;
    }
    else{
        cout << cntmn * cntmx;
    }
}