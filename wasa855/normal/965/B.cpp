#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
char a[106][106];
int vis[106][106];
int n,k;
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%s",&a[i]);
    int col=0,row=0,cnt=0,tot=0;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]=='.')
            {
                cnt=0;
                for(int z=j;z<min(n,j+k);z++)
                    if(a[i][z]=='.') cnt++;
                if(cnt==k){
                    for(int z=j;z<min(n,j+k);z++)
                        vis[i][z]++;
                }
                cnt=0;
                for(int z=i;z<min(n,i+k);z++)
                    if(a[z][j]=='.') cnt++;
                if(cnt==k){
                    for(int z=i;z<min(n,i+k);z++)
                        vis[z][j]++;
                }
            }
            if(vis[i][j]>tot)
            {
                tot=vis[i][j];
                row=i;
                col=j;
            }
        }
    }
    printf("%d %d\n",row+1,col+1);
    return 0;
}