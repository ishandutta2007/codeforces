#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
    int n;cin>>n;int a[n];for(int i=0;i<n;++i) {cin>>a[i];--a[i];}
    int ans[n][2];for(int i=0;i<n;++i) for(int j=0;j<2;++j) ans[i][j]=0;
    for(int i=0;i<n;++i) {int u=ans[a[i]][0];int v=ans[a[i]][1];if(i%2==0) ans[a[i]][0]=max(ans[a[i]][0],v+1);else ans[a[i]][1]=max(ans[a[i]][1],u+1);}
    for(int i=0;i<n;++i) {cout<<max(ans[i][0],ans[i][1])<<' ';} cout<<'\n';
    }
    return 0;
}