#include<bits/stdc++.h>
using namespace std;
const int N=1005,R=230;
const int dx[4]={0,1,-1,0},dy[4]={1,0,0,-1};
struct node
{
    int x,y,d;
    node(int xx=0,int yy=0,int dd=0){x=xx,y=yy,d=dd;};
};
vector<node>rats;
char s[N][N];
int reach[N][N],vx[R*R],vy[R*R],ma[N][N],n,m,d,cnt_rats=0,size=0;
bool va[R*R][R],vis[N][N];
void put_set(int x,int y,int type)
{
    if(!reach[x][y])
    {
        va[++size][type]=1;
        vx[size]=x;
        vy[size]=y;
        return ;
    }
    for(int i=1;i<=size;i++)
	{
	    if(vx[i]==x&&vy[i]==y)
		{
	        va[i][type]=1;
	        break;
	    }
	}
}
void bfs(int type,node st)
{
    memset(vis,0,sizeof(vis));
    queue<node>q;
    q.push(st);
    vis[st.x][st.y]=1;
    while(!q.empty())
    {
        node u=q.front();
        q.pop();
        put_set(u.x,u.y,type);
        reach[u.x][u.y]=1;
        if(u.d==d)
			continue;
        for(int i=0;i<4;i++)
        {
            int x=u.x+dx[i],y=u.y+dy[i];
            if(x<1||x>n||y<1||y>m||vis[x][y]||ma[x][y])
				continue;
            vis[x][y]=1;
            q.push(node(x,y,u.d+1));
        }
    }   
}
int main()
{
#ifdef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int ans1,ans2,flag=0;
    scanf("%d%d%d",&n,&m,&d);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s[i]+1);
        for(int j=1;j<=m;j++)
        if(s[i][j]=='R')
			cnt_rats++;
    }
    if(cnt_rats>R)
	{
		printf("-1\n");
		return 0;
	}
    for(int i=1;i<=n;i++)
    {
	    for(int j=1;j<=m;j++)
	    {
	        ma[i][j]=0;
	        if(s[i][j]=='X')
				ma[i][j]=1;
	        if(s[i][j]=='R')
				rats.push_back(node(i,j,0));
	    }
	}
    for(int i=0;i<cnt_rats;i++)
    	bfs(i,rats[i]);
    if(size==1)
    {
        for(int i=0;i<cnt_rats;i++)
	    {
	        if(va[1][i]==0)
	        {
	            printf("-1\n");
	            return 0;
	        }
		}
        printf("%d %d ",vx[1],vy[1]);
        for(int i=1;i<=n;i++)
        {
	        for(int j=1;j<=m;j++)
	        {
	            if(ma[i][j]||(i==vx[1]&&j==vy[1]))
					continue;
	            printf("%d %d\n",i,j);
	            return 0;
	        }
		}
    }
    for(int i=1;i<size;i++)
    {

        for(int j=i+1;j<=size;j++)
        {
            flag=1;
            for(int k=0;k<cnt_rats;k++)
            if(va[i][k]==0&&va[j][k]==0)
            {
                flag=0;
                break;
            }
            if(flag)
			{
                ans1=i;
                ans2=j;
                break;
            }
        }   
        if(flag)
			break;
    }
    if(flag)
		printf("%d %d %d %d\n",vx[ans1],vy[ans1],vx[ans2],vy[ans2]);
    else 
		printf("-1\n");
	return 0;
}