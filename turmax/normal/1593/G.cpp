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
        string s;
        cin>>s;
        int n=s.size();
        int a[n];
        int pr[n+1];
        for(int i=0;i<n;++i)
        {
            if(s[i]=='(' || s[i]==')')
            {
                a[i]=1;
            }
            else
            {
                a[i]=0;
            }
        }
        pr[0]=0;pr[1]=a[0];
        for(int i=2;i<=n;++i)
        {
            pr[i]=pr[i-2]+a[i-1];
        }
        int q;
        cin>>q;
        while(q--)
        {
            int l,r;
            cin>>l>>r;
            l--;
            if(l%2==0)
            {
                int sum1=(pr[r]-pr[l]);
                int sum2;
                if(l!=0) sum2=pr[r-1]-pr[l-1];
                else sum2=pr[r-1];
                cout<<abs(sum2-sum1)<<'\n';
            }
            else
            {
                int sum1=(pr[r]-pr[l]);
                int sum2;
                if(l!=0) sum2=pr[r-1]-pr[l-1];
                else sum2=pr[r-1];
                cout<<abs(sum2-sum1)<<'\n';
            }
        }
    }
    return 0;
}