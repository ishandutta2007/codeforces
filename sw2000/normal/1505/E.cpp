#include<bits/stdc++.h>
using namespace std;

int n,m;
char boa[10][10];
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>boa[i];
    int x=0,y=0,ans=0;
    while(x<n&&y<m)
    {
        if(boa[x][y]=='*')ans++;
        if(x==n-1)y++;
        else if(y==m-1)x++;
        else if(boa[x+1][y]=='*')x++;
        else y++;
    }
    cout<<ans;
    return 0;
}