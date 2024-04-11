#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, mw = 0, mb = 0, t;
    cin >> n;
    int m = n / 2;
    int a[m];
    for (int i = 0; i < m; i++) cin >> a[i];
    sort(a, a + m);
    for (int i = 0; i < m; i++){
        mb += abs(a[i] - i * 2 - 1);
    }
    for (int i = 0; i < m; i++){
        mw += abs(a[i] - i * 2 - 2);
    }
    cout << min(mb, mw);
}