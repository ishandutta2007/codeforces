#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, x, ans = 0;
    cin >> n;
    int a[n + 2];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    cin >> m;
    int b[m + 2];
    for (int i = 0; i < m; i++){
        cin >> b[i];
    }
    sort(b, b + m);
    bool vis[m + 2] = {0};
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (abs(a[i] - b[j]) <= 1 && !vis[j]){
                ans++;
                vis[j] = 1;
                break;
            }
        }
    }
    cout << ans;
}