#include<bits/stdc++.h>
using namespace std;

//#define int long long

const int N = 1e6 + 5, oo = 1e9 + 7;

int n, mx = oo, ans;
int a[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = n; i >= 1; i--){
        if(mx > i) ans++;
        mx = min(mx, i - a[i]);
    }
    cout << ans;
}