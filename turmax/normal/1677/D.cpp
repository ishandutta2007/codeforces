#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=998244353;
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) {
    int n,k;cin>>n>>k;
    int a[n];for(int i=0;i<n;++i) cin>>a[i];
    int ans=1;for(int i=1;i<=k;++i) {ans*=i;ans%=p;} for(int i=0;i<n-k;++i) {if(a[i]==(-1)) {ans*=(i+k+1);} else if(a[i]==0) {ans*=(k+1);} ans%=p;}
    for(int i=n-k;i<n;++i) if(a[i]!=0 && a[i]!=(-1)) ans=0;
    cout<<(ans%p+p)%p<<'\n';
    }
    return 0;
}