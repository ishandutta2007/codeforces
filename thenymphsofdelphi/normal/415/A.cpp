#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int a[n + 1];
    memset(a, 0, sizeof(a));
    while (m--){
        int x;
        cin >> x;
        for (int i = x; i <= n; i++){
            if (a[i] != 0) break;
            a[i] = x;
        }
    }
    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
}