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
        int n,m;
        cin>>n>>m;
        string s[n];
        for(int i=0;i<n;i++)
            cin>>s[i];
        bool r[2]={},w[2]={};
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(s[i][j]=='R')
                    r[(i+j)%2]=true;
                else if(s[i][j]=='W')
                    w[(i+j)%2]=true;
        if(r[0]&&r[1]||
           r[1]&&w[1]||
           w[1]&&w[0]||
           w[0]&&r[0])
        {
            cout<<"NO\n";
            continue;
        }
        string res="RW";
        if(r[1]||w[0])
            res="WR";
        cout<<"YES\n";
        for(int i=0;i<n;i++,cout<<"\n")
            for(int j=0;j<m;j++)
                cout<<res[(i+j)%2];
    }
}