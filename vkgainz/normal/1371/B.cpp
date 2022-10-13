#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin >> t;
    while(t--){
        ll n, r;
        cin >> n >> r;
        if(n>r){
            ll ans = r*(r+1)/2;
            cout << ans << endl;
        }
        else{
            
            ll ans =(n-1)*(n)/2;
            ans++;
            cout << ans << endl;
        }
    }
}