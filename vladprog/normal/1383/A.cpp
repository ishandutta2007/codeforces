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
        string a,b;
        cin>>n>>a>>b;
        bool is[20][20]={};
        bool ok=true;
        for(int i=0;i<n;i++)
        {
            char x=a[i],y=b[i];
            if(x>y)
                ok=false;
            else if(x<y)
                is[x-'a'][y-'a']=true;
        }
        if(!ok)
        {
            cout<<-1<<"\n";
            continue;
        }
        int ans=0;
        for(int i=0;i<20;i++)
        {
            int mn=-1;
            for(int j=0;j<20;j++)
                if(is[i][j])
                    if(mn==-1)
                        mn=j;
                    else
                        is[mn][j]=true;
            if(mn!=-1)
                ans++;
        }
        cout<<ans<<"\n";
    }
}