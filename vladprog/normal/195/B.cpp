#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int a[2]={m/2+1,m/2},i=m%2;
    vector<int> ans;
    for(int j=0;j<n;j++)
    {
//        cout<<i<<" "<<a[0]<<" "<<a[1]<<"\n";
        if(i==0) a[i]--; else a[i]++;
//        cout<<i<<" "<<a[0]<<" "<<a[1]<<"\n\n";
        if(a[i]<1||a[i]>m)
            break;
        ans.push_back(a[i]);
        i=!i;
    }
    for(int i=0;i<n;i++)
        cout<<ans[i%m]<<"\n";
}