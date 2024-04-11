#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n,k; cin >> n >> k;
    ll val = 0;
    ll sum = 0;
    for(int i=0;i<k;i++){
        int a,b;
        cin >> a >> b;
        val+=a*1LL*b;
        sum+=b;
    }
    val%=n;
    if(val<0) val+=n;
    if(sum>n) cout << -1 << endl;
    else if(sum<n) cout << 1 << endl;
    else {
        ll comp = n*1LL*(n+1)/2%n;
        if(comp<0) comp+=n;
        if(comp!=val) cout << -1 << endl;
        else cout << 1 << endl;
    }
}