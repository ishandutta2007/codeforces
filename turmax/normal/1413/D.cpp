#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int ans[n];
    stack <pair<int,int> > v;
    int curr=0;
    for(int i=0;i<2*n;++i)
    {
        char u;
        cin>>u;
        if(u=='+')
        {
            v.push({1,curr});
            ++curr;
        }
        else if(u=='-')
        {
            int x;
            cin>>x;
            if(v.empty())
            {
                cout<<"NO";
                return 0;
            }
            pair <int,int> o=v.top();
            if(o.first>x)
            {
                cout<<"NO";
                return 0;
            }
            ans[o.second]=x;
            v.pop();
            if(!v.empty())
            {
                pair <int,int> z=v.top();
                z.first=max(x,z.first);
                v.pop();
                v.push(z);
            }
        }
    }
    cout<<"YES"<<endl;
    for(int i=0;i<n;++i)
    {
        cout<<ans[i]<<' ';
    }
    return 0;
}