#include<iostream>
#include<cstdio>
#include<queue>
#include<vector> 
using namespace std;
inline int read()
{
    int n=0,f=1,ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        n=n*10+ch-'0';
        ch=getchar();
    }
    return n*f;
}
struct bbian
{
    int u,v,w,nex;
}a[5000004];
queue<int>que;
int head[400001],cur[400001],tmp=1;
int dep[400001],n;
int s,t,sth;
void addb(int x,int y,int z)
{
    a[++tmp].u=x;
    a[tmp].v=y;
    a[tmp].w=z;
    a[tmp].nex=head[x];
    head[x]=tmp;
}
bool bfs()
{
    for(int i=1;i<=t;i++)dep[i]=0;
    que.push(s);
    dep[s]=1;
    while(!que.empty())
    {
        sth=que.front();
        que.pop();
        for(int i=head[sth];i;i=a[i].nex)
        {
            if(dep[a[i].v]==0&&a[i].w>0)
            {
                dep[a[i].v]=dep[sth]+1;
                que.push(a[i].v);
            }
        }
    }
    if(dep[t]==0)return false;
    return true;
}
int dfs(int x,int f)
{
    if(x==t)return f;
    for(int& i=cur[x];i;i=a[i].nex)
    {
        if((dep[a[i].v]==dep[a[i].u]+1)&&a[i].w!=0)
        {
            int ff=dfs(a[i].v,min(f,a[i].w));
            if(ff>0)
            {
                a[i].w-=ff;
                a[i^1].w+=ff;
                return ff;
            }
        }
    }
    return 0;
}
int qz[400005],pos[400005];
vector<int>ys[400005];
int main()
{
    int m,x,y,z;
    int sjzs;
    sjzs=read();
    for(int i=1;i<=50000;i++)
    {
    	for(int j=2*i;j<=50000;j+=i)
    	{
    		ys[j].push_back(i);
		}
	}
    for(int greg=1;greg<=sjzs;greg++)
    {
    	n=read();
    	for(int i=1;i<=n;i++)qz[i]=read(),pos[qz[i]]=i;
    	for(int i=1;i<=n;i++)
    	{
    		for(int j=0;j<ys[qz[i]].size();j++)
    		{
    			x=ys[qz[i]][j];
    			if(pos[x]==0)continue;
    			addb(i,pos[x]+2*n,1);
    			addb(pos[x]+2*n,i,0);
    			addb(i+n,pos[x]+3*n,1);
    			addb(pos[x]+3*n,i+n,0);
			}
		}
		for(int i=1;i<=n;i++)
		{
			addb(i+n,i+2*n,1);
			addb(i+2*n,i+n,0);
		}
		s=4*n+1;
		t=4*n+2;
		for(int i=1;i<=2*n;i++)
		{
			addb(s,i,1);
			addb(i,s,0);
			addb(i+2*n,t,1);
			addb(t,i+2*n,0);
		}
    	int ans=0;
    	while(bfs())
  	  	{
  	      	for(int i=1;i<=t;i++)cur[i]=head[i];
  	      	while(x=dfs(s,1000000000))ans+=x;
  	  	}
    	cout<<ans-n<<endl;
    	for(int i=1;i<=4*n+2;i++)head[i]=0;
    	tmp=1;
    	for(int i=1;i<=n;i++)pos[qz[i]]=0;
    }
    return 0;
}