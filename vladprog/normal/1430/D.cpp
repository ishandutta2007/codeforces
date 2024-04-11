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
        string s;
        cin>>n>>s;
        vector<int> v;
        char p='2';
        for(char c:s)
        {
            if(c==p)
                v.back()++;
            else
                v.push_back(1);
            p=c;
        }
        int del=0,eq=0,ans=0;
        while(del<v.size())
        {
            ans++;
            eq=max(eq,del);
            while(eq<v.size()&&v[eq]==1)
                eq++;
            if(eq==v.size())
                del++;
            else
                v[eq]--;
            del++;
        }
        cout<<ans<<"\n";
    }
}