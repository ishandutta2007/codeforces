#include<iostream>
using namespace std;

int main()
{
    int m,n;
    cin>>m>>n;
    bool a[m][n],c[m][n],b[m][n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            b[i][j]=0;
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
            if(a[i][j]==0)
            {
                for(int k=0;k<m;k++)
                {
                    b[k][j]=1;
                }
                for(int k=0;k<n;k++)
                {
                    b[i][k]=1;
                }
            }
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(b[i][j]==0)
            {
                b[i][j]=1;
            }
            else
            {
                b[i][j]=0;
            }
            c[i][j]=0;
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(b[i][j]==1)
            {
                for(int k=0;k<m;k++)
                {
                    c[k][j]=1;
                }
                for(int k=0;k<n;k++)
                {
                    c[i][k]=1;
                }
            }
           // cout<<c[i][j]<<" ";
        }
    }
    bool trueman=1;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]!=c[i][j])
            {
                trueman=0;
            }
        }
    }
    if(trueman==0)
    cout<<"NO";
    else
    {
        cout<<"YES"<<endl;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<b[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    
    return 0;
}