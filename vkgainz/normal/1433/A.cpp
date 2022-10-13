#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t; cin >> t;
    while(t--) {
        int x; cin >> x;
        int a = x%10;
        int len = 0;
        while(x>0) x/=10, ++len;
        int ans = 10*(a-1);
        ans+=len*(len+1)/2;
        cout << ans << endl;
    }
}