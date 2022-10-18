#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, cnt = 0;
    cin >> n;
    int a[n + 2], b[n + 2];
    memset(b, 1, sizeof(b));
    a[0] = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    a[n + 1] = 0;
    for (int i = 1; i <= n + 1; i++){
        if (a[i] == 0 && a[i - 1] == 0){
            b[i] = 0;
            b[i - 1] = 0;
        }
    }
    for (int i = 1; i <= n; i++){
        if (b[i]){
            cnt++;
        }
    }
    cout << cnt;
}