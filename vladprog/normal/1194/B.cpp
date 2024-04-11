#include<bits/stdc++.h>

using namespace std;

const int N=5e4+100;
string s[N];
int x[N],y[N];

int main()
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
        for(int i=0;i<n;i++)
            cin>>s[i];
        for(int i=0;i<n;i++)
            x[i]=0;
        for(int j=0;j<m;j++)
            y[j]=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(s[i][j]=='.')
                    x[i]++,
                    y[j]++;
        int ans=n+m-1;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                ans=min(ans,x[i]+y[j]-(s[i][j]=='.'));
        cout<<ans<<"\n";
    }
}