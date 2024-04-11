#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=(1e9+7);
bool can[(1<<20)];
int cou=1;
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,q;
    cin>>n>>q;
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    pair <int,pair<int,int> > b[q];
    for(int i=0;i<q;++i)
    {
        cin>>b[i].first>>b[i].second.first;b[i].second.second=i;
        b[i].first--;
    }
    sort(b,b+q);
    can[0]=true;
    int curr=0;
    int ans[q];
    for(int i=0;i<n;++i)
    {
        if(!can[a[i]])
        {
            for(int j=0;j<(1<<20);++j)
            {
                if(can[j])
                {
                    can[j^a[i]]=true;
                }
            }
        }
        else
        {
            cou*=2;
            cou%=p;
        }
        while(curr<q && b[curr].first==i)
        {
            //cout<<curr<<" "<<b[curr].second.second<<endl;
            if(can[b[curr].second.first])
            {
                ans[b[curr].second.second]=cou;
            }
            else
            {
                ans[b[curr].second.second]=0;
            }
            ++curr;
        }
    }
    for(int i=0;i<q;++i)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}