#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=110;

int x[N],y[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++)
            cin>>x[i]>>y[i];
        bool yes=false;
        for(int i=1;i<=n;i++)
        {
            bool cur=true;
            for(int j=1;j<=n;j++)
                if(abs(x[i]-x[j])+abs(y[i]-y[j])>k)
                    cur=false;
            yes|=cur;
        }
        cout<<(yes?1:-1)<<"\n";
    }
}