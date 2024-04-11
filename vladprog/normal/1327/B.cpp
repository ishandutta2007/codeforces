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
        set<int> free;
        for(int i=1;i<=n;i++)
            free.insert(i);
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            int k;
            cin>>k;
            int cur=0;
            while(k--)
            {
                int g;
                cin>>g;
                if(!cur&&free.count(g))
                    cur=g;
            }
            if(cur)
                free.erase(cur);
            else
                ans=i;
        }
        if(ans)
            cout<<"IMPROVE\n"<<ans<<" "<<*free.begin()<<"\n";
        else
            cout<<"OPTIMAL\n";
    }
}