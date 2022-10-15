#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod=998244353;
int n,k,pw[200007];

signed main(){
    cin>>n;
    pw[0]=1;
    for (int i=1;i<=n;++i){
        pw[i]=pw[i-1]*10%mod;
    }
    for (int i=1;i<n;++i){
        cout<<(180*pw[n-i-1]+81*(n-i-1)*pw[n-i-1])%mod<<" ";
    }
    cout<<10;
    return 0;
}