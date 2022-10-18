#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

const int N=1e5+100;

int a[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        int l=1,r=n;
        while(l<r)
        {
            r--;
            if(l>1&&a[l])
                l--;
            for(int i=l;i<=r;i++)
                a[i]=a[i+1]-a[i];
            sort(a+l,a+r+1);
            while(l<r&&!a[l])
                l++;
        }
        cout<<a[r]<<"\n";
    }
}