#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=210;

set<int> s[N];
set<int> c[N];

bool solve(int n,int start)
{
    vector<int> ans{start};
    for(int i=1;i<=n-1;i++)
        c[i]=s[i],
        c[i].erase(start);
    while(true)
    {
        int ind=-1;
        for(int i=1;i<=n-1;i++)
            if(c[i].size()==1)
                ind=i;
        if(ind==-1)
            break;
        int val=*c[ind].begin();
        ans.push_back(val);
        set<int> need;
        for(int i=int(ans.size())-1;need.size()<s[ind].size();i--)
            need.insert(ans[i]);
        if(s[ind]!=need)
            return false;
        for(int i=1;i<=n-1;i++)
            c[i].erase(val);
    }
    if(ans.size()!=n)
        return false;
    for(int x:ans)
        cout<<x<<" ";
    cout<<"\n";
    return true;
}

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
        for(int i=1;i<=n;i++)
            s[i].clear();
        for(int i=1;i<=n-1;i++)
        {
            int k;
            cin>>k;
            while(k--)
            {
                int x;
                cin>>x;
                s[i].insert(x);
            }
        }
        for(int i=1;i<=n;i++)
            if(solve(n,i))
                break;
    }
}