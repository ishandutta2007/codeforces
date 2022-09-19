#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;++i) {for(int j=0;j<m;++j) {cin>>a[i][j];if((i+j)%2==0) cout<<720720<<' ';else cout<<720720+a[i][j]*a[i][j]*a[i][j]*a[i][j]<<' ';} cout<<endl;}
    return 0;
}