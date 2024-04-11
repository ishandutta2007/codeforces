#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n; cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    int low = 1000000000;
    int cnt =0;
    for(int i=n-1;i>=0;i--){
        if(a[i]<=low){
            low = a[i];
        }
        else{
            cnt++;
        }
    }
    cout << cnt << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--) solve();
}