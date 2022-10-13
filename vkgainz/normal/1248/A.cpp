#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a1 = 0;
        for(int i=0;i<n;i++){
            int x; cin >> x;
            a1+=x%2;
        }
        int m; cin >> m;
        int b1 = 0;
        for(int i=0;i<m;i++){
            int x; cin >> x;
            b1+=x%2;
        }
        ll ans = a1*1LL*b1+(n-a1)*1LL*(m-b1);
        cout << ans << endl;

    }
}