#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

int n,m,k,n1,num,num1,top,tot,ans,lca,col,flag;
int stack[100010],p[100010],p1[100010],b[100010],used[100010],vis[100010],g[100010],c[100010],d[100010];

struct edge
{int u,v,next;
};
struct edge e[200010],e1[200010];

struct node
{int d,dfn,fa[21];
};
struct node a[100010];

bool cmp(int i,int j)
{return a[i].dfn<a[j].dfn;
}

long long min1(long long aa,long long bb)
{return aa<bb?aa:bb;
}

void add(int u,int v)
{e[num].u=u;
 e[num].v=v;
 e[num].next=p[u];
 p[u]=num;
 num++;
 
 e[num].u=v;
 e[num].v=u;
 e[num].next=p[v];
 p[v]=num;
 num++;
}

void add1(int u,int v)
{e1[num1].u=u;
 e1[num1].v=v;
 e1[num1].next=p1[u];
 p1[u]=num1;
 num1++;
}

void get_lca(int x,int y)
{int i,t;
 
 if(a[x].d<a[y].d)
 {  t=x;
    x=y;
    y=t;
 }
 
 for(i=20;i>=0;i--)
    if(a[x].d-(1<<i)>=a[y].d)
        x=a[x].fa[i];
 
 for(i=20;i>=0;i--)
    if(a[x].fa[i]!=a[y].fa[i])
    {   x=a[x].fa[i];
        y=a[y].fa[i];
    }

 if(x!=y)
    lca=a[x].fa[0];
 else
    lca=x;
}

void work(int i,int fa)
{int j;

 for(j=1;j<=20;j++)
    a[i].fa[j]=a[a[i].fa[j-1]].fa[j-1];
 
 tot++;
 a[i].dfn=tot;
 j=p[i];
 while(j!=-1)
 {  if(e[j].v!=fa)
    {   a[e[j].v].fa[0]=i;
        a[e[j].v].d=a[i].d+1;
        work(e[j].v,i);
    }
    j=e[j].next;
 }
}

void build()
{int i;
 
 //cout<<"DD"<<endl;
 n1=0;
 num1=0;
 top=1;
 stack[top]=1;
 for(i=1;i<=k;i++)
 {  get_lca(stack[top],b[i]);
    while(a[stack[top]].d>a[lca].d) 
    {   if(a[stack[top-1]].d>a[lca].d)
        {   add1(stack[top-1],stack[top]);
            n1++;
            used[n1]=stack[top-1];
            //d[n1]=c[stack[top-1]];
        }
        else
        {   add1(lca,stack[top]);
            n1++;
            used[n1]=lca;
            //d[used[n1]]=c[lca];
        }
        top--;
    }
    if(stack[top]!=lca)
    {   top++;
        stack[top]=lca;
    }
    if(lca!=b[i])
    {   top++;
        stack[top]=b[i];
    }
 }
 
 for(i=1;i<top;i++)
 {  add1(stack[i],stack[i+1]);
    n1++;
    used[n1]=stack[i];
 }
}

void calc(int i,int fa)
{int j;
 
 g[i]=0;
 if(c[i]==col) g[i]=1;
 j=p1[i];
 while(j!=-1)
 {  if(e1[j].v!=fa)
    {   calc(e1[j].v,i);
        g[i]+=g[e1[j].v];
    }
    j=e1[j].next;
 }
 if(g[i]>=2)
 {  g[i]=0;
    ans++;
 }
 else if(g[i]==1)
 {  if(a[fa].d+1==a[i].d && c[i]==col && c[fa]==col)
        flag=0;
    if(c[fa]==col)
    {   ans++;  
        g[i]=0;
    }
 }
}

int main()
{//freopen("repair9.in","r",stdin);
 //freopen("repair.out","w",stdout);
 
 int i,j,x,y,z;
 
 scanf("%d",&n);
 
 memset(p,-1,sizeof(p));
 for(i=1;i<n;i++)
 {  scanf("%d%d",&x,&y);
    add(x,y);
 }
 
 a[1].d=1;
 work(1,0);
 /*
 for(i=1;i<=n;i++)
    cout<<a[i].dfn<<" ";
 cout<<endl;    
 */
 scanf("%d",&m);
 
 memset(p1,-1,sizeof(p1));
 
 for(i=1;i<=m;i++)
 {  scanf("%d",&k);
    col++;
    for(j=1;j<=k;j++)
    {   scanf("%d",&b[j]);
        vis[b[j]]=1;
        c[b[j]]=col;
    }
    sort(b+1,b+k+1,cmp);    
    build();
    /*
    cout<<n1<<endl;
    for(j=0;j<num1;j++)
        cout<<e1[j].u<<" "<<e1[j].v<<endl;
    cout<<endl; 
    */
    ans=0;
    flag=1;
    calc(1,0);
    
    if(flag)
        printf("%d\n",ans);
    else
        printf("%d\n",-1);  
    
    for(j=1;j<=n1;j++)
        p1[used[j]]=-1;
    for(j=1;j<=k;j++)
        vis[b[j]]=0;
 }
 
 return 0;
}