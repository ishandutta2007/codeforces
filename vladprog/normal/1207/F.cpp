#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=500000,S=707;
int a[N+1],b[S+1][S+1];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin>>q;
    while(q--)
    {
        int t,x,y;
        cin>>t>>x>>y;
        if(t==1)
        {
            a[x]+=y;
            for(int i=1;i<=S;i++)
                b[i][x%i]+=y;
        }
        else if(x<=S)
            cout<<b[x][y]<<"\n";
        else
        {
            int ans=0;
            for(int i=y;i<=N;i+=x)
                ans+=a[i];
            cout<<ans<<"\n";
        }
    }
}