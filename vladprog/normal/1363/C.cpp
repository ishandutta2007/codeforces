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
        int n,x;
        cin>>n>>x;
        int cnt=0;
        for(int i=1;i<=n-1;i++)
        {
            int u,v;
            cin>>u>>v;
            if(u==x||v==x)
                cnt++;
        }
        if(cnt<=1||n%2==0)
            cout<<"Ayush\n";
        else
            cout<<"Ashish\n";
    }
}