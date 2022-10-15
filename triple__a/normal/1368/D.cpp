#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,a[200007],b[200007];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    for (int i=0;i<n;++i) cin>>a[i];
    for (int j=0;j<20;++j){
        int res=0;
        for (int i=0;i<n;++i) res+=(a[i]>>j&1);
        for (int i=0;i<res;++i) b[i]|=(1<<j);
    }
    int ans=0;
    for (int i=0;i<n;++i){
        ans+=b[i]*b[i];
    }
    cout<<ans<<endl;
    return 0;
}