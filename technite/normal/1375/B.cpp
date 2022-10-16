#include<bits/stdc++.h>
using namespace std;
int mx[]={1,-1,0,0};
int my[]={0,0,-1,1};
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        bool x=true;
        vector<vector<int>> v(n,vector<int>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>v[i][j];
                if(i==0||i==n-1||j==m-1||j==0)
                {
                    if(v[i][j]==4) x=false;
                }
                if(v[i][j]>4) x=false;
            }
        }
        if(!x)
        {
            cout<<"NO"<<'\n';
            continue;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                    int val=v[i][j];
                    int cn=0;
                    for(int k=0;k<4;k++)
                    {
                        int x=i+mx[k],y=j+my[k];

                        if(x>=0&&x<n&&y>=0&&y<m)
                        {
                            cn++;
                        }
                    }
                    if(cn>=val)
                    {
                        v[i][j]=cn;
                    }
                    else
                    {
                        x=false;
                    }

                
            }
        }
       if(!x)
        {
            cout<<"NO"<<'\n';
            continue;
        }
        cout<<"YES"<<"\n";
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<v[i][j]<<" ";
            }
            cout<<'\n';
        }
    }
}