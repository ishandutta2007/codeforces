#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    int p=(n-k+2)/2;
    for(int i=1;i<=n;i++)
        cout<<bool(i%p);
}