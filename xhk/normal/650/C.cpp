#include<bits/stdc++.h>
using namespace std;

struct edge
{int u,v,next;
};
struct edge e[12000010];

struct unit
{int x,num;
};
struct unit b[2000010];

int n,m,num,tot,col;
int head[2000010],used[2000010],c[2000010],sa[2000010],f[2000010],fa[2000010],d[2000010],q[2000010],v[4][2]={0,1,1,0,-1,0,0,-1};
vector<int> a[1500010];

#define num(i,j) ((i-1)*m+j)

bool cmp(unit A,unit B)
{return A.x<B.x;
}

int find(int i)
{return fa[i]==i?i:fa[i]=find(fa[i]);
}

void add(int u,int v)
{e[num].u=u;
 e[num].v=v;
 e[num].next=head[u];
 head[u]=num;
 num++;
}

int check(int i,int j)
{if(i<=0 || i>n || j<=0 || j>m) return 0;
 return 1;
}

int main()
{int i,j,x,y,fx,fy,k,t,w;
 
 scanf("%d%d",&n,&m);
 for(i=1;i<=n;i++)
 {	a[i].push_back(0);
 	for(j=1;j<=m;j++)
 	{	scanf("%d",&x);
 		a[i].push_back(x);
 		sa[++tot]=x;
 	}
 }
 memset(head,-1,sizeof(head));
 sort(sa+1,sa+tot+1);
 for(i=1;i<=n;i++)
 	for(j=1;j<=m;j++)
	{	a[i][j]=lower_bound(sa+1,sa+tot+1,a[i][j])-sa;
		fa[num(i,j)]=num(i,j);	
	}
 for(i=1;i<=n;i++)
 {	col++;
 	tot=0;
 	for(j=1;j<=m;j++)
		if(used[a[i][j]]==col)
		{	fx=find(c[a[i][j]]);
			fy=find(num(i,j));
			if(fx!=fy) fa[fx]=fy;
		} 	
		else
		{	used[a[i][j]]=col;
			c[a[i][j]]=num(i,j);
		}
 }	
 for(j=1;j<=m;j++)
 {	col++;
 	tot=0;
 	for(i=1;i<=n;i++)
 		if(used[a[i][j]]==col)
 		{	fx=find(c[a[i][j]]);
		 	fy=find(num(i,j));
 			if(fx!=fy) fa[fx]=fy;
 		}
 		else
 		{	used[a[i][j]]=col;
			c[a[i][j]]=num(i,j);
		}
 }
 for(i=1;i<=n;i++)
 {	col++;
 	tot=0;
 	for(j=1;j<=m;j++)
		if(used[a[i][j]]!=col)
		{	used[a[i][j]]=col;
			b[++tot].x=a[i][j];
			b[tot].num=find(num(i,j));
		}
	sort(b+1,b+tot+1,cmp);	
	for(j=1;j<tot;j++)
	{	add(find(b[j].num),find(b[j+1].num));
		d[find(b[j+1].num)]++;
		//cout<<i<<" "<<find(b[j].num)<<" "<<find(b[j+1].num)<<endl;
		//cout<<find(3)<<endl;
	}
 }
 for(j=1;j<=m;j++)
 {	col++;
 	tot=0;
 	for(i=1;i<=n;i++)
 		if(used[a[i][j]]!=col)
 		{	used[a[i][j]]=col;
			b[++tot].x=a[i][j];
			b[tot].num=find(num(i,j));
		}
 	sort(b+1,b+tot+1,cmp);	
	for(i=1;i<tot;i++)
	{	add(find(b[i].num),find(b[i+1].num));	
		d[find(b[i+1].num)]++;
	}
 }
 //cout<<find(11)<<" "<<find(12)<<endl;
 for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
 	{	for(k=0;k<=3;k++)
	 	{	x=i+v[k][0];
		 	y=j+v[k][1];
			if(!check(x,y)) continue;
			fx=find(num(i,j));
			fy=find(num(x,y));
			if(a[i][j]<a[x][y])
			{	add(fx,fy);
				d[fy]++;
			}
		}
	}
 t=1;
 w=0;		
 for(i=1;i<=n*m;i++)
 	if(d[i]==0)
	{	q[++w]=i;
		f[i]=1;
	}
 while(t<=w)
 {	j=head[q[t]];
 	while(j!=-1)
	{	d[e[j].v]--;
		f[e[j].v]=max(f[e[j].v],f[q[t]]+1);
		//cout<<e[j].v<<" "<<f[e[j].v]<<endl;
		if(d[e[j].v]==0) q[++w]=e[j].v;
		j=e[j].next;
	}
	t++;
 }
 for(i=1;i<=n;i++)
 	for(j=1;j<=m;j++)
 	{	printf("%d",f[find(num(i,j))]);
 		if(j!=m)
		 	printf(" ");
		else
			printf("\n");
	}
 return 0;
}