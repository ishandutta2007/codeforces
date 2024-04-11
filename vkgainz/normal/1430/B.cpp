#include <bits/stdc++.h>
using namespace std;
 
#define ll long long

int main(){
    int t; cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        ll ans = 0;
        ll a[n];
        for(int i=0;i<n;i++) {
            cin >> a[i];
        }
        sort(a,a+n);
        for(int i=0;i<k;i++) {
            if(n-i-2<0) continue;

            a[n-1]+=a[n-i-2];
        }
        cout << a[n-1] << endl;
    }
}