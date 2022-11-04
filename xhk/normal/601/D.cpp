#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
using namespace std;

struct edge
{int v,next;
};
struct edge e[600010];

struct trie
{int ch[26];
};
struct trie t[4500010];

int n,tot,num,ans,s1;
int p[300010],c[300010],d[300010],root[300010],s[4500010];
char a[300010];
vector<int> rec;

int get_node()
{int ret,i;
 
 if(!rec.empty())
 {	ret=rec.back();
 	rec.pop_back();
	for(i=0;i<26;i++)
 		t[ret].ch[i]=0;
 	return ret;
 }
 else
 {	tot++;
 	return tot;
 }
}

void add(int u,int v)
{e[num].v=v;
 e[num].next=p[u];
 p[u]=num;
 num++;
 
 e[num].v=u;
 e[num].next=p[v];
 p[v]=num;
 num++;
}

void merge(int &i,int x)
{int j;
 
 if(i==0) i=get_node();
 
 s[i]=1;
 for(j=0;j<26;j++)
 {	if(t[x].ch[j])
 		merge(t[i].ch[j],t[x].ch[j]);
	s[i]+=s[t[i].ch[j]];
 }
 rec.push_back(x);
}

void work(int i,int fa)
{int j,k=0;
 
 //cout<<i<<" "<<fa<<endl;
 
 j=p[i];
 while(j!=-1)
 {	if(e[j].v!=fa)
 	{	work(e[j].v,i);
 		if(d[e[j].v]>d[k])
 			k=e[j].v;
 	}
 	j=e[j].next;
 }
 
 //return ;
 if(k!=0)
 {	root[i]=root[k];
 	j=p[i];
 	while(j!=-1)
 	{	if(e[j].v!=fa && e[j].v!=k)
 			merge(root[i],root[e[j].v]);
 		j=e[j].next;
 	}
 	tot++;
 	t[tot].ch[a[i]-97]=root[i];
 	s[tot]=s[root[i]]+1;
 	root[i]=tot;
 }
 else
 {	tot++;
 	root[i]=tot;
 	s[tot]=2;
 	tot++;
 	t[root[i]].ch[a[i]-97]=tot;
 	s[tot]=1;
 }
 d[i]=s[root[i]]-1;
 //cout<<i<<" "<<d[i]<<endl;
}

int main()
{int i,j,x,y;
 
 scanf("%d",&n);
 
 for(i=1;i<=n;i++)
 	scanf("%d",&c[i]);
 
 scanf("%s",a+1);
 
 memset(p,-1,sizeof(p));
 for(i=1;i<n;i++)
 {	scanf("%d%d",&x,&y);
 	add(x,y);
 } 
 
 work(1,0);
 
 ans=0;
 s1=0;
 for(i=1;i<=n;i++)
 	if(c[i]+d[i]>ans)
 	{	ans=c[i]+d[i];
 		s1=1;
	}
	else if(c[i]+d[i]==ans)
		s1++;
 
 //printf("%d\n",tot);
 
 printf("%d\n%d\n",ans,s1);
 
 return 0;		
}