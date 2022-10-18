#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int a[n], b[n];
    int ans = -1;
    for (int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        if (b[i] == 0){
            a[i]--;
            b[i] = 100;
        }
        if (a[i] < m){
            ans = max(ans, 100 - b[i]);
        }
    }
    cout << ans;
}