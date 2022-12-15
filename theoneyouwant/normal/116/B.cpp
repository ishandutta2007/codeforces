#include<iostream>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    char c[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>c[i][j];
        }
    }
    int counter=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(c[i][j]=='W')
            {
                bool w=0;
                if(i!=0 && c[i-1][j]=='P')
                {
                    w=1;
                }
                if(i!=n-1 && c[i+1][j]=='P')
                {
                    w=1;
                }
                if(j!=0 && c[i][j-1]=='P')
                {
                    w=1;
                }
                if(j!=m-1 && c[i][j+1]=='P')
                {
                    w=1;
                }
                if(w==1)
                {
                    counter++;
                }
            }
        }
    }
    cout<<counter;
    return 0;
}