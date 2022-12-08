
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,n) for(int i=1;i<=n;++i)


int a[200005];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        ++k;
        rep(i,n) cin>>a[i];
        sort(a+1,a+1+n);
        if(k==1 || n==1)
        {
            cout << a[1] << endl;
        }
        else
        {
            int ans = a[1], mx = 1e9;
            for(int i=1;i+k-1<=n;++i)
            {
                if((a[i+k-1]-a[i]+1) / 2 < mx) mx = (a[i+k-1]-a[i]+1)/2, ans = (a[i+k-1]+a[i])/2;
            }
            cout<<ans<<endl;
        }
    }
}