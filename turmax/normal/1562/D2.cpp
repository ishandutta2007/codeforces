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
        int n,q;
        cin>>n>>q;
        string s;
        cin>>s;
        int pr[n+1];
        pr[0]=0;
        for(int i=1;i<=n;++i) {pr[i]=pr[i-1];int o=1;{if(s[i-1]=='+') o=1; else o=(-1);} if(i%2==1) o*=(-1); pr[i]+=o;}
        while(q--)
        {
            int l,r;
            cin>>l>>r;
            l--;
            int ans1=pr[r]-pr[l];
            if(ans1==0)
            {
                cout<<0<<'\n';
                continue;
            }
            else if(abs(ans1%2)==1)
            {
                cout<<1<<'\n';
                int currr=r;
                int currl=(l-1);
                int res=(-1);
                while(true)
                {
                    int mid=(currl+currr)/2;
                    int val=(pr[mid]-pr[l])-(pr[r]-pr[mid+1]);
                    if(val==0)
                    {
                        res=mid;
                        break;
                    }
                    if(val*(pr[r]-pr[l])>=0)
                    {
                        currr=mid;
                    }
                    else
                    {
                        currl=mid;
                    }
                }
                assert(res!=(-1));
                cout<<res+1<<'\n';
                continue;
            }
            else
            {
                cout<<2<<'\n';
                if((r-l)==2)
                {
                    cout<<l+1<<' '<<l+2<<'\n';
                    continue;
                }
                int currr=r;
                int currl=l;
                int res=(-1);
                while(true)
                {
                    int mid=(currl+currr)/2;
                    int val=(pr[mid]-pr[l+1])-(pr[r]-pr[mid+1]);
                    if(val==0)
                    {
                        res=mid;
                        break;
                    }
                    if(val*(pr[r]-pr[l+1])>=0)
                    {
                        currr=mid;
                    }
                    else
                    {
                        currl=mid;
                    }
                }
                assert(res!=(-1));
                cout<<l+1<<' '<<res+1<<'\n';
                continue;
            }
        }
    }
    return 0;
}