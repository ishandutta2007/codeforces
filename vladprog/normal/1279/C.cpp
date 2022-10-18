#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

const int N=1e5+100;

int a[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        int top=1,ans=m;
        set<int>s;
        while(m--)
        {
            int b;
            cin>>b;
            if(s.count(b))
            {
                s.erase(b);
                continue;
            }
            ans+=s.size()*2;
            while(a[top]!=b)
            {
                s.insert(a[top++]);
                ans+=2;
            }
            top++;
        }
        cout<<ans<<"\n";
    }
}