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
        int a[n+1];
        for(int i=1;i<=n;++i) a[i]=i;
        vector <pair<int,int> > res;
        int curr=n;
        int i=(curr-1);
        while(true)
        {
            //cout<<curr<<" curr "<<i<<" i "<<endl;
            if(curr<=2) break;
            if(curr==5)
            {
                res.push_back({2,5});
                res.push_back({5,3});
                res.push_back({3,4});
                res.push_back({4,5});
                res.push_back({4,5});
                break;
            }
            if(curr==4)
            {
                res.push_back({3,4});
                res.push_back({4,2});
                res.push_back({4,2});
                break;
            }
            if(curr==3)
            {
                res.push_back({3,2});
                res.push_back({3,2});
                break;
            }
            if((i-1)*(i-1)>=curr)
            {
                res.push_back({i,curr});
                i--;
            }
            else
            {
                res.push_back({curr,i});
                res.push_back({curr,i});
                //cout<<curr<<" curr "<<endl;
                curr=i;
                i--;
            }
        }
        cout<<res.size()<<endl;
        for(auto h:res)
        {
            cout<<h.first<<' '<<h.second<<endl;
        }
        //for(int i=1;i<=n;++i) cout<<a[i]<<' ';
        //cout<<endl;
    }
    return 0;
}