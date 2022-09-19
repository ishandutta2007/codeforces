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
        int a[n];
        for(int i=0;i<n;++i)  cin>>a[i];
        int res1[n];
        int res2[n];
        set <int> ok1,ok2;
        for(int i=1;i<=n;++i) {ok1.insert(i);ok2.insert(i);}
        for(int i=0;i<n;++i)
        {
            if(i==0 || a[i]!=a[i-1])
            {
                res1[i]=a[i];
                res2[i]=a[i];
                ok1.erase(a[i]);
                ok2.erase(a[i]);
            }
            else
            {
                res1[i]=(*ok1.begin());
                ok1.erase(ok1.begin());
                res2[i]=(*(--ok2.upper_bound(a[i])));
                ok2.erase(res2[i]);
            }
        }
        for(auto h:res1) cout<<h<<' ';
        cout<<endl;
        for(auto h:res2) cout<<h<<' ';
        cout<<endl;
    }
    return 0;
}