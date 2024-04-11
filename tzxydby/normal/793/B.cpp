#include<bits/stdc++.h>
using namespace std;
const int N=1005;
const int k[4][2]={-1,0,0,-1,1,0,0,1};
int n,m;
int vis[N][N];
char a[N][N];
struct pos
{
    int i,j,k,l;
};
queue<pos>q;
void bfs(int ex,int ey)
{
    pos c,t;
    while(!q.empty())
		q.pop();
    for(int i=0;i<4;i++)
	{
        int x=ex+k[i][0],y=ey+k[i][1];
        if(x>=0&&x<n&&y>=0&&y<m)
		{
            if(a[x][y]=='.')
			{
                vis[x][y]=1;
                c.i=x;
				c.j=y;
                c.k=i;
				c.l=0;
                q.push(c);
            }
        }
    }
    while(!q.empty())
	{
        c=q.front();q.pop();
        for(int i=0;i<4;i++)
		{
            int x=c.i+k[i][0],y=c.j+k[i][1];
            if(x>=0&&x<n&&y>=0&&y<m)
			{
                if(c.k==i)
				{
                    if(a[x][y]=='.')
					{
                        vis[x][y]=1;
                        t.i=x;
						t.j=y;
                        t.k=i;
						t.l=c.l;
                        q.push(t);
                    }
                }
                else if((i%2==0&&c.k%2==1)||(i%2==1&&c.k%2==0))
				{
                    if(a[x][y]=='.'&&c.l!=1)
					{
                        vis[x][y]=1;
                        t.i=x;
						t.j=y;
                        t.k=i;
						t.l=1;
                        q.push(t);
                    }
                }
                else
					continue;
            }
        }
    }
}
int get_ans(int x,int y)
{
    int ans=0;
    for(int i=x+1;i<n;i++)
	{
        if(vis[i][y]==1)
		{
            ans=1;
            break;
        }
        if(a[i][y]=='*')
			break;
    }
    for(int i=x-1;i>=0;i--)
	{
        if(vis[i][y]==1)
		{
            ans=1;
            break;
        }
        if(a[i][y]=='*')
			break;
    }
    for(int i=y+1;i<m;i++)
	{
        if(vis[x][i]==1)
		{
            ans=1;
            break;
        }
       if(a[x][i]=='*')
			break;
    }
    for(int i=y-1;i>=0;i--)
	{
        if(vis[x][i]==1)
		{
            ans=1;
            break;
        }
        if(a[x][i]=='*')
			break;
    }
    return ans;
}

int main()
{
    int sx,sy,ex,ey,ans=0;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%s",a[i]);
    for(int i=0;i<n;i++)
	{
        for(int j=0;j<m;j++)
		{
            if(a[i][j]=='S')
			{
                vis[i][j]=1;
                ex=i;ey=j;
            }
            if(a[i][j]=='T')
			{
                sx=i;sy=j;
            }
        }
    }
    bfs(ex,ey);
	ans=get_ans(sx,sy);
    if(ans)
		printf("YES\n");
    else
		printf("NO\n");
    return 0;
}
//