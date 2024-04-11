#include <bits/stdc++.h>

using namespace std;
#define int unsigned long long
int po[20];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int u1=1;
    for(int i=0;i<=19;++i)
    {
        po[i]=u1;
        u1*=10;
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n,s;
        cin>>n>>s;
        string h=to_string(n);
        int pr[h.size()+1];pr[0]=0;
        for(int i=0;i<h.size();++i) pr[i+1]=pr[i]+(h[i]-'0');
        int ans=1;
        for(int i=0;i<19;++i) ans*=10;
        for(int k=0;k<=h.size();++k)
        {
            int val;
            if(k!=0)
            val=pr[h.size()-k]-pr[0]+1;
            else
            val=pr[h.size()-k]-pr[0];
            if(val<=s && k==0) {ans=0;break;}
            if(val<=s)
            {
                ans=min(ans,po[k]-n%po[k]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}