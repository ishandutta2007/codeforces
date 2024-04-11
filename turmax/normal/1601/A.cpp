#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];int b[60]={0};
        for(int i=0;i<n;++i) {cin>>a[i];for(int j=0;j<60;++j) {b[j]+=((bool) (a[i] & (1<<j)));}}
        for(int i=1;i<=n;++i)
        {
            bool ok=true;
            for(int j=0;j<60;++j) ok=(ok && b[j]%i==0);
            if(ok) cout<<i<<' ';
        }
        cout<<endl;
    }
    return 0;
}