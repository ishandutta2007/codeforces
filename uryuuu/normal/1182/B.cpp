#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define tm(a,b,c) max(max(a,b),c)
#define inf 0x3f3f3f3f
const ll Mod=1e9+7;
#define maxn 50010
using namespace std;
int dd[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
char a[505][505];
int main()
{
    int n,m;
    int s,sum=0;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
            if(a[i][j]=='*')
                sum++;
        }
    }
    int flag=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]!='*')
                continue;
            s=1;
            int ff=0;
            for(int k=0;k<4;k++)
            {
                flag=0;
                int x=i,y=j;
                while(1)
                {
                    x+=dd[k][0];
                    y+=dd[k][1];
                    if(x<0||y<0||x>=n||y>=m)
                        break;
                    if(a[x][y]!='*')
                        break;
                    s++;
                    flag=1;
                }
                if(flag==0)
                {
                    ff=1;
                    break;
                }
            }
            if(ff==1)
                continue;
            if(s==sum)
            {
                cout<<"YES"<<endl;
                return 0;
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}