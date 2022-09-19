#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    t=1;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int a[n*k];
        vector <int> v[n];int pr[n*k];for(int i=0;i<(n*k);++i) pr[i]=(-1);
        for(int i=0;i<(n*k);++i) {cin>>a[i];a[i]--;if(!v[a[i]].empty()) {pr[i]=v[a[i]].back();} v[a[i]].push_back(i);}
        bool used[n]={0};
        pair <int,int> res[n];
        for(int i=0;i<((n+k)/(k-1));++i)
        {
            int l=(i*(k-1));int r=min(n,((i+1)*(k-1)));
            int l1=0;
            for(int j=0;j<(n*k);++j)
            {
                if(a[j]>=l && a[j]<r && !used[a[j]] && pr[j]>=l1)
                {
                    res[a[j]]={pr[j]+1,j+1};
                    l1=(j+1);
                    used[a[j]]=true;
                }
            }
        }
        for(auto h:res) cout<<h.first<<' '<<h.second<<endl;
    }
    return 0;
}