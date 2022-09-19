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
        int a[n],b[n];
        for(int i=0;i<n;++i) cin>>a[i]; for(int i=0;i<n;++i) cin>>b[i];
        sort(a,a+n);sort(b,b+n);
        bool ok=true;
        for(int i=0;i<n;++i) {ok=(ok && (b[i]-a[i])>=0);ok=(ok && (b[i]-a[i])<=1);}
        if(ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}