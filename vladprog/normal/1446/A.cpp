#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,W;
        cin>>n>>W;
        vector<int> ans;
        int cur=0;
        for(int i=1;i<=n;i++)
        {
            int w;
            cin>>w;
            if((W+1)/2<=cur&&cur<=W)
                continue;
            if(w>W)
                continue;
            if((W+1)/2<=w&&w<=W)
            {
                ans.clear();
                ans.push_back(i);
                cur=w;
                continue;
            }
            ans.push_back(i);
            cur+=w;
        }
        if((W+1)/2<=cur&&cur<=W)
        {
            cout<<ans.size()<<"\n";
            for(int i:ans)
                cout<<i<<" ";
            cout<<"\n";
        }
        else
            cout<<-1<<"\n";
    }
}