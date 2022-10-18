#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, k;
int a[N], c[N];
bool b[N];

int main(){
int t; cin >> t;
while (t--){
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = 0;
    }
    int ans = 0, idx = 0;
    for (int i = 2; i < n; i++){
        if (a[i] > a[i - 1] && a[i] > a[i + 1]){
            b[i] = 1;
        }
    }
    for (int i = 1; i <= n; i++){
        c[i] = c[i - 1] + (b[i]);
    }
    for (int i = k; i <= n; i++){
        int tans = c[i] - c[i - k];
        // cout << i - k + 1 << ' ' << tans << ' ';
        if (b[i]) tans--;
        if (b[i - k + 1]) tans--;
        // cout << tans << endl;
        if (ans < tans + 1){
            ans = tans + 1;
            idx = i - k + 1;
        }
    }
    cout << ans << ' ' << idx << endl;
}
}