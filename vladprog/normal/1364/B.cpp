#include<bits/stdc++.h>

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
        int n;
        cin>>n;
        vector<int> ans;
        while(n--)
        {
            int p;
            cin>>p;
            int k=ans.size();
            if(ans.size()>=2&&( (ans[k-1]>ans[k-2])==(p>ans[k-1]) ))
                ans.pop_back();
            ans.push_back(p);
        }
        cout<<ans.size()<<"\n";
        for(int x:ans)
            cout<<x<<" ";
        cout<<"\n";
    }
}