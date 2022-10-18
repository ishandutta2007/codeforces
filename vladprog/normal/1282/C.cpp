#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

const int N=2e5+100;

pair<int,int> tx[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m;
    cin>>m;
    while(m--)
    {
        int n,T,a,b;
        cin>>n>>T>>a>>b;
        int easy=0,hard=0;
        for(int i=1;i<=n;i++)
            cin>>tx[i].second,
            (tx[i].second?hard++:easy++);
        for(int i=1;i<=n;i++)
            cin>>tx[i].first;
        tx[n+1]={T+1,2};
        n++;
        sort(tx+1,tx+n+1);
        int need_easy=0,need_hard=0;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(i>1&&tx[i].first==tx[i-1].first)
            {
                if(tx[i].second==1)
                    need_hard++;
                else if(tx[i].second==0)
                    need_easy++;
                continue;
            }
            int all=tx[i].first-1;
            all-=need_easy*a+need_hard*b;
            if(all<0)
            {
                if(tx[i].second==1)
                    need_hard++;
                else if(tx[i].second==0)
                    need_easy++;
                continue;
            }
            int res=need_easy+need_hard;
            if(all>=(easy-need_easy)*a+(hard-need_hard)*b)
                res+=(easy-need_easy)+(hard-need_hard);
            else if(all>=(easy-need_easy)*a)
                res+=(easy-need_easy)+(all-(easy-need_easy)*a)/b;
            else
                res+=all/a;
            ans=max(ans,res);
            if(tx[i].second==1)
                need_hard++;
            else if(tx[i].second==0)
                need_easy++;
        }
        cout<<ans<<"\n";
    }
}