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
        string a,b;
        cin>>a>>b;
        vector<int> ans;
        for(int i=0;i<n;i++)
            if(a[i]!=b[i])
                ans.push_back(i+1),
                ans.push_back(1),
                ans.push_back(i+1);
        cout<<ans.size()<<"\n";
        for(int p:ans)
            cout<<p<<" ";
        cout<<"\n";
    }
}