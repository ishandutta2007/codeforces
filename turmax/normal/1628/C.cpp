#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n][n];for(int i=0;i<n;++i) for(int j=0;j<n;++j) cin>>a[i][j];
        char u[n][n];for(int i=0;i<n;++i) for(int j=0;j<n;++j) u[i][j]='.';
        int res=0;
        for(int s=0;s<=2*n-2;++s)
        {
            if(s%4==0)
            {
                int val=0;
                if(s>=n-1) val=((n-1)%2);
                for(int x=0;x<=s;++x)
                {
                    int y=s-x;
                    if(x<n && y<n && (x-val)%2==0)
                    {
                        u[x][y]='#';
                        res^=a[x][y];
                    }
                }
            }
        }
        for(int s=0;s<=2*n-2;++s)
        {
            if(s%4==0)
            {
                int val=0;
                if(s>=n-1) val=((n-1)%2);
                for(int x1=0;x1<=s;++x1)
                {
                    int x=n-1-x1;
                    int y=s-x1;
                    if(x>=0 && y<n && (x1-val)%2==0)
                    {
                        u[x][y]='#';
                        res^=a[x][y];
                    }
                }
            }
        }
        #ifdef LOCAL
        for(int i=0;i<n;++i) {for(int j=0;j<n;++j) cout<<u[i][j]; cout<<endl;}
        #endif // LOCAL
        cout<<res<<'\n';
    }
    return 0;
}