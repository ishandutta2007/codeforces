#pragma GCC optimize("O3")
#include <bits/stdc++.h>

typedef long long ll;
#define int ll
typedef long double ld;

using namespace std;

int play(vector<int> a,int i)
{
    int t=a[i];
    a[i]=0;
    int d=t/14,r=t%14;
    for(int i=0;i<14;i++)
        a[i]+=d;
    while(r--)
        a[(++i)%14]++;
    int res=0;
    for(int i=0;i<14;i++)
        if(a[i]%2==0)
            res+=a[i];
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> a(14);
    for(int i=0;i<14;i++)
        cin>>a[i];
    int ans=0;
    for(int i=0;i<14;i++)
        ans=max(ans,play(a,i));
    cout<<ans;
}