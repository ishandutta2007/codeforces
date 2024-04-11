#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N=1e5+100;

int a[N],k[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]<1||a[i]>n||k[a[i]])
            a[i]=0;
        k[a[i]]++;
    }
    for(int i=1,j=1;i<=n;i++)
    {
        if(!a[i])
        {
            while(k[j])
                j++;
            a[i]=j;
            k[j]++;
        }
        cout<<a[i]<<" ";
    }
}