#include <bits/stdc++.h>

using namespace std;
#define int long long
int query(int x)
{
    cout<<"? "<<x<<endl;
    int ans;
    cin>>ans;
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        bool used[n+1]={0};
        int ans[n+1];for(int i=1;i<=n;++i) ans[i]=(-1);
        for(int i=1;i<=n;++i)
        {
            if(!used[i])
            {
                int lst=i;
                vector <int> v;
                while(true)
                {
                    lst=query(i);
                    //cout<<lst<<" lst "<<endl;
                    v.push_back(lst);
                    if(used[lst]) break;
                    used[lst]=true;
                }
                used[i]=true;
                for(int j=0;j<v.size()-1;++j) ans[v[j]]=v[j+1];
            }
        }
        cout<<"! ";for(int i=1;i<=n;++i) cout<<ans[i]<<' ';
        cout<<endl;
    }
    return 0;
}