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
        int pr[n+1];pr[0]=0;
        int mi=0;
        for(int i=0;i<n;++i)
        {
            if(s[i]=='-')
            {
                pr[i+1]=pr[i]-1;
            }
            else
            {
                pr[i+1]=pr[i]+1;
            }
            mi=min(mi,pr[i+1]);
        }
        int l=0;
        int res=0;
        for(int i=0;i<=(-mi);++i)
        {
            res+=l;
            for(int j=(l+1);j<=n;++j)
            {
                ++res;
                if((pr[j]+i)<0)
                {
                    break;
                }
                ++l;
            }
            //cout<<res<<" res "<<endl;
            //cout<<l<<" l "<<endl;
        }
        cout<<res<<endl;
    }
    return 0;
}