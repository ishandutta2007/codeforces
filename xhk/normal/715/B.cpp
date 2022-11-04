#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

struct edge
{int u,v,c,f,next;
};
struct edge e[200010];

int n,m,l,S,T,col,num;
int head[100010],pre[200010],used[100010],q[1000010];
long long dis[100010];

void add(int u,int v,int c,int f)
{e[num].u=u;
 e[num].v=v;
 e[num].c=c;
 e[num].f=f;
 e[num].next=head[u];
 head[u]=num;
 num++;
 e[num].u=v;
 e[num].v=u;
 e[num].c=c;
 e[num].f=f;
 e[num].next=head[v];
 head[v]=num;
 num++;
}

void spfa()
{int i,j,t,w;
 
 pre[S]=-1;
 col++;
 for(i=1;i<=n;i++) dis[i]=-1;
 dis[S]=0;
 t=1;
 w=1;
 q[t]=S;
 while(t<=w)
 {	//cout<<t<<" "<<w<<endl;
 	used[q[t]]=0;
 	j=head[q[t]];
 	while(j!=-1)
	{	if(dis[e[j].v]==-1 || dis[q[t]]+e[j].c<dis[e[j].v])
		{	dis[e[j].v]=dis[q[t]]+e[j].c;
			pre[e[j].v]=j;
			//cout<<e[j].v<<" "<<dis[e[j].v]<<" "<<dis[q[t]]<<" "<<e[j].c<<endl;
			//if(e[j].v==T && dis[T]!=-1 && dis[T]<l) return;
			if(used[e[j].v]!=col)
			{	used[e[j].v]=col;
				q[++w]=e[j].v;
			}
		}
		j=e[j].next;
	}
	t++;
 }
}

int main()
{int i,j,x,y,z;
 
 scanf("%d%d%d%d%d",&n,&m,&l,&S,&T);
 memset(head,-1,sizeof(head));
 S++;
 T++;
 for(i=1;i<=m;i++)
 {	scanf("%d%d%d",&x,&y,&z);
	if(z)
		add(x+1,y+1,z,0);
	else
		add(x+1,y+1,1,1);
 }
 //cout<<e[1].c<<endl;
 memset(pre,-1,sizeof(pre));
 spfa();
 if(dis[T]>l)
 {	printf("NO\n");
 	return 0;
 }
 else if(dis[T]==l)
 {	printf("YES\n");
 	for(i=0;i<num;i+=2)
 		printf("%d %d %d\n",e[i].u-1,e[i].v-1,e[i].c);
 	return 0;
 }
 j=pre[T];
 while(j!=-1)
 {	if(e[j].f==1)
  	{	e[j].f=-1;
  		e[j^1].f=-1;
  	}
  	j=pre[e[j].u];
 }
 for(i=0;i<num;i++)
 	if(e[i].f==1)
 		e[i].c=1000000001;
 	else if(e[i].f==-1)
 	{	e[i].f=1;
 		e[i].c=1;
 	}
 //cout<<e[1].c<<endl;
 while(dis[T]<l)
 {	j=pre[T];
	//cout<<"HH"<<endl;
 	while(j!=-1 && !e[j].f)
	{	
		j=pre[e[j].u];
	}
 	//cout<<"kk"<<endl;
 	if(j==-1)
 	{	printf("NO\n");
 		return 0;
 	}
 	e[j].c+=l-dis[T];
 	e[j^1].c+=l-dis[T];
 	spfa();
 }
 if(dis[T]==l)
 {	printf("YES\n");
 	for(i=0;i<num;i+=2)
 		printf("%d %d %d\n",e[i].u-1,e[i].v-1,e[i].c);
 }
 else
 	printf("NO\n");
 return 0;
}