#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;int a[n+1]={0};for(int i=0;i<n;++i) cin>>a[i];
        reverse(a,a+n);
        for(int i=n;i>=2;--i)
        {
            bool ok=true;
            for(int j=0;j<i-1;++j)
            {
                if(a[j]==0) {sort(a,a+j);reverse(a,a+j);ok=false;break;}
                a[j]-=a[j+1];
            }
            if(ok) {sort(a,a+i-1);reverse(a,a+i-1);}
            //for(int j=0;j<i-1;++j) {cout<<a[j]<<' ';} cout<<endl;
        }
        cout<<a[0]<<'\n';
    }
    return 0;
}