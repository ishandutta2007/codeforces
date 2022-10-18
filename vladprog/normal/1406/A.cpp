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
        int cnt[110]={};
        while(n--)
        {
            int x;
            cin>>x;
            cnt[x]++;
        }
        int a=-1,b=-1;
        for(int i=0;i<110;i++)
            if(cnt[i]==0)
            {
                if(a==-1)
                    a=i;
                if(b==-1)
                    b=i;
            }
            else if(cnt[i]==1)
            {
                if(a==-1)
                    a=i;
            }
        cout<<a+b<<"\n";
    }
}