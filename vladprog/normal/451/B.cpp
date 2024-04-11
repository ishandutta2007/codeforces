#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=1e5+100;
int a[N],b[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],b[i]=a[i];
    sort(b+1,b+n+1);
    int l=-1,r=-1;
    for(int i=1;i<=n;i++)
        if(a[i]!=b[i])
        {
            r=i;
            if(l==-1)
                l=i;
        }
    if(l==-1)
        cout<<"yes\n1 1\n",exit(0);
    for(int i=l,j=r;i<r;i++,j--)
        if(a[i]!=b[j])
            cout<<"no",exit(0);
    cout<<"yes\n"<<l<<" "<<r;
}