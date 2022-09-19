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
        vector <pair<int,int> > a(n);
        vector <pair<int,int> > b(n);
        map <pair<int,int>,int> o;
        for(int i=0;i<n;++i) {cin>>a[i].first>>a[i].second;o[a[i]]=i;}
        b=a;
        sort(a.begin(),a.end());
        int mia[n+1];int mii[n+1];
        int curr=1e18;int curri=(-1);
        mia[0]=1e18;mii[0]=(-1);
        for(int i=0;i<n;++i)
        {
            if(a[i].second<curr)
            {
                curr=a[i].second;
                curri=i;
            }
            mii[i+1]=curri;mia[i+1]=curr;
        }
        vector <int> ans(n);
        for(int i=0;i<n;++i)
        {
            int j=lower_bound(a.begin(),a.end(),make_pair(a[i].first,(int) -1e18))-a.begin();
            //cout<<j<<" j "<<endl;
            //cout<<mia[j]<<" mia[j] "<<endl;
            if(mia[j]<a[i].second)//???
            {
                ans[o[a[i]]]=o[a[mii[j]]];
                continue;
            }
            j=lower_bound(a.begin(),a.end(),make_pair(a[i].second,(int) -1e18))-a.begin();
           // cout<<j<<" j "<<endl;
            if(mia[j]<a[i].first)//???
            {
                ans[o[a[i]]]=o[a[mii[j]]];
                continue;
            }
            //cout<<" tgfr "<<endl;
            ans[o[a[i]]]=(-1);
        }
        for(int i=0;i<n;++i) {if(ans[i]!=(-1)) ++ans[i];}
        for(int i=0;i<n;++i) cout<<ans[o[b[i]]]<<' ';
        cout<<endl;
    }
    return 0;
}