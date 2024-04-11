#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
int main(){
    int n; cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a,a+n);
    ll ans = 0;
        int x = 0;
        int y = 0;
        for(int i=0;i<n;i++){
            if(i<n/2) x+=a[i];
            else y+=a[i];
        }
        ans = x*1LL*x+y*1LL*y;
        cout << ans << endl;
}