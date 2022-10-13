#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        int b[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        for(int i=0;i<n;i++) cin >> b[i];
        int minA =1000000000;
        int minB =1000000000;
        for(int i=0;i<n;i++){
            minA = min(minA,a[i]);
            minB = min(minB,b[i]);
        }
        ll ans =0;
        for(int i=0;i<n;i++){
            ans+=max(a[i]-minA,b[i]-minB);
        }
        cout << ans << endl;
    }
}