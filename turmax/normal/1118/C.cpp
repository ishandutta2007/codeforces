#include <bits/stdc++.h>

using namespace std;

int main()
{
    #define int long long
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    int t;
    cin>>n;
    int a[n][n];
    vector <int> b (n*n);
    for(int i=0;i<n*n;++i)
    {
        cin>>t;
        b[i]=t;
    }
    sort(b.begin(),b.end());
    int u=0;
    if(n%2==0)
    {
        int k=-1;
        while(u<(n*n))
        {
            ++k;
            if(b[u]==b[u+1] && b[u+1]==b[u+2] && b[u+2]==b[u+3])
            {
                a[k/(n/2)][k%(n/2)]=b[u];
                a[n-1-k/(n/2)][k%(n/2)]=b[u];
                a[n-1-k/(n/2)][n-1-k%(n/2)]=b[u];
                a[k/(n/2)][n-1-k%(n/2)]=b[u];
                u+=4;
            }
            else
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    else
    {
        int k=0;
        int p=0;
        int y=0;
        int v=0;
        while(u<(n*n))
        {
            if(b[u]==b[u+1] && b[u+1]==b[u+2] && b[u+2]==b[u+3] && v<(n/2)*(n/2))
            {
                a[k/(n/2)][k%(n/2)]=b[u];
                a[n-1-k/(n/2)][k%(n/2)]=b[u];
                a[n-1-k/(n/2)][n-1-k%(n/2)]=b[u];
                a[k/(n/2)][n-1-k%(n/2)]=b[u];
                u+=4;
                v++;
                ++k;
            }
            else if(b[u]==b[u+1])
            {
                if(y>(n-1))
                {
                    cout<<"NO"<<endl;
                    return 0;
                }
                if(y<n/2)
                {
                    a[y][n/2]=b[u];
                    a[n-1-y][n/2]=b[u+1];
                    u+=2;
                    y++;
                }
                else
                {
                    a[n/2][y-(n/2)]=b[u];
                    a[n/2][n-1-(y-(n/2))]=b[u+1];
                    u+=2;
                    y++;
                }
            }
            else
            {
                if(p==1)
                {
                    cout<<"NO"<<endl;
                    return 0;
                }
                a[n/2][n/2]=b[u];
                p=1;
                ++u;
            }
        }
    }
    cout<<"YES"<<endl;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<""<<endl;
    }
    return 0;
}