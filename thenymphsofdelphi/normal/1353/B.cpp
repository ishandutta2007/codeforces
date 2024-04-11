#include<bits/stdc++.h>
using namespace std;

int n, k;
int a[31], b[31];

int main(){
    int t; cin >> t;
    while (t--){
        cin >> n >> k;
        int ans = 0;
        for (int i = 1; i <= n; i++){
            cin >> a[i]; ans += a[i];
        }
        for (int i = 1; i <= n; i++){
            cin >> b[i];
        }
        sort(a + 1, a + 1 + n);
        sort(b + 1, b + 1 + n);
        for (int i = n; i >= n - k + 1; i--){
            if (b[i] > a[n + 1 - i]){
                ans += b[i] - a[n + 1 - i];
            }
            else{
                break;
            }
        }
        cout << ans << endl;
    }
}