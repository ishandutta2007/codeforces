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
        int n;
        cin>>n;
        vector<int> ans;
        while(n--)
        {
            int cur;
            cin>>cur;
            ans.push_back(0);
            while(ans.back()+1!=cur)
                ans.pop_back();
            ans.back()++;
            for(int i=0;i<ans.size();i++)
                cout<<ans[i]<<".\n"[i==ans.size()-1];
        }
    }
}