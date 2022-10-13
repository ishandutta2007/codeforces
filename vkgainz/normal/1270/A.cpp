#include <bits/stdc++.h>
using namespace std;

#define ll long long
void solve(){
    int n; cin >> n;
    int k1, k2; cin >> k1 >> k2;
    int a[k1], b[k2];
    for(int i=0;i<k1;i++) cin >> a[i];
    for(int i=0;i<k2;i++) cin >> b[i];
    sort(a,a+k1); sort(b,b+k2);
    (a[k1-1]>b[k2-1]) ? cout << "YES" << endl : cout << "NO" << endl;
}
int main(){
    int t; cin >> t;
    while(t--) solve();
}