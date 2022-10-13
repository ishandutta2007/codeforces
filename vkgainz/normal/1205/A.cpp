#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n; cin >> n;
    if(n*1LL*(2*n+1)%2==0) cout << "NO" << endl;
    else {
        vector<int> ans(2*n);
        for(int i=0;i<n;i++) {
            if(i%2) {
                ans[i] = (2*i+1);
            }
            else {
                ans[i] = (2*i+2);
            }
        }
        for(int i=n;i<2*n;i++) {
            if(ans[i-n]%2==0) ans[i] = ans[i-n]-1;
            else ans[i] = ans[i-n]+1;
        }
        cout << "YES" << endl;
        for(int i=0;i<2*n;i++) cout << ans[i] << endl;
    }
}