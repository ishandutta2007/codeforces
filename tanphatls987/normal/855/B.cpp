#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1e5+10;
const ll inf=3e18;
int n;
ll a[N],m1,m2,m3;
ll L[N],R[N];
int main() {
    cin>>n>>m1>>m2>>m3;
    for(int i=1;i<=n;i++) cin>>a[i];


    L[0]=R[n+1]=-inf;
    for(int i=1;i<=n;i++) L[i]=max(L[i-1],m1*a[i]);

    for(int i=n;i>=1;i--) R[i]=max(R[i+1],m3*a[i]);
    ll ans=-inf;
    for(int i=1;i<=n;i++) ans=max(ans,m2*a[i]+L[i]+R[i]);
    cout<<ans;
 }