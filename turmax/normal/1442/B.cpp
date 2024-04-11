#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=998244353;
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int a[n];
        int u[n];
        for(int i=0;i<n;++i) {cin>>a[i];a[i]--;u[a[i]]=i;}
        int b[k];
        for(int i=0;i<k;++i) {cin>>b[i];b[i]--;b[i]=u[b[i]];}
        reverse(b,b+k);
        int ans=1;
        set <int> d;
        d.insert(-1);
        d.insert(n);
        bool h=true;
        for(int i=0;i<k;++i)
        {
            int x=b[i];
            set <int>::iterator it=d.upper_bound(x);
            int r=(*it);
            it--;
            int l=(*it);
            if((r-l)==2)
            {
                cout<<0<<endl;
                h=false;
                break;
            }
            if((r-x)!=1 && (x-l)!=1)
            {
                ans*=2;
                ans%=p;
            }
            d.insert(x);
        }
        if(h) cout<<ans<<endl;
    }
    return 0;
}