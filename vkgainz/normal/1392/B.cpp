#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n; cin >> n;
    ll k; cin >> k;
    ll a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    ll max = -1000000000;
    ll min = 1000000000;
    for(int i=0;i<n;i++){
        if(a[i]>max) max= a[i];
        if(a[i]<min) min = a[i];
    }
    if(k%2){
        for(int i=0;i<n;i++)
            a[i] = max-a[i];
    }
    else{
        for(int i=0;i<n;i++)
            a[i] = a[i]-min;
    }
    for(int i=0;i<n;i++)
        cout << a[i] << " ";
    cout << endl;
}
int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}