#include <bits/stdc++.h>
using namespace std;
char g[920][920];
int main()
{
    int n,m,k,num=0;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        	cin>>g[i][j];
    for(int r=1;r<=n;r++)
    { 
        for(int i=2;i<n;i++)
        { 
            for(int j=2;j<m;j++)
            {
                if((i-r)>=1&&(j-r)>=1&&g[i][j]=='*'&&g[i+r][j]=='*'&&g[i-r][j]=='*'&&g[i][j+r]=='*'&&g[i][j-r]=='*')
                {
                    if(num==k-1)
                    {
                        cout<<i<<" "<<j<<endl
							<<i-r<<" "<<j<<endl
							<<i+r<<" "<<j<<endl
							<<i<<" "<<j-r<<endl
							<<i<<" "<<j+r<<endl;
                        return 0;
                    }
                    else num++;
                }
            }
        }
    } 
    puts("-1");
    return 0;
}