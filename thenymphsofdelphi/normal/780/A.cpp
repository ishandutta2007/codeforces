#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, x, mx = -1, s = 0;
    cin >> n;
    int a[n];
    memset(a, 0, sizeof(a));
    for (int i = 0; i < 2 * n; i++){
        cin >> x;
        x--;
        a[x]++;
        s++;
        if (a[x] == 2){
            a[x] = 0;
            s -= 2;
        }
        mx = max(s, mx);
    }
    cout << mx;
}