#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int inf=0x3f3f3f3f;
const char ch[100]={"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"};
int r,c,k;
int boa[110][110];

int wx[4]={0,1,0,-1},wy[4]={1,0,-1,0},cnt,id,sum;
char ans[110][110];

void solve()
{
    int x=1,y=1,st=0;
    for(int i=0;i<r*c;i++)
    {
        if(ans[x+wx[st]][y+wy[st]]!=0)
        {
            st++;
            st%=4;
        }

        if(boa[x][y]==1&&cnt==sum/(k-id))
        {
            id++;
            sum-=cnt;
            cnt=0;
        }
        ans[x][y]=ch[id];
        if(boa[x][y]==1)cnt++;
        x+=wx[st],y+=wy[st];
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {
        memset(boa,-1,sizeof(boa));
        memset(ans,-1,sizeof(ans));
        cnt=0,sum=0,id=0;
        cin>>r>>c>>k;
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++)
            {
                char a;
                cin>>a;
                if(a=='.')boa[i][j]=0;
                else
                {
                    boa[i][j]=1;
                    sum++;
                }
                ans[i][j]=0;
            }
        }
        solve();

        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++)
            {
                printf("%c",ans[i][j]);
            }
            puts("");
        }
    }

    return 0;
}