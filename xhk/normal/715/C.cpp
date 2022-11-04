#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

#define ll long long

struct edge
{int u,v,c,next;
};
struct edge e[400010];

struct node
{int size,ms;
};
struct node f[100010];

int n,mod,num,root,size,tot,cnt;
int head[100010],pw[100010],ipw[100010],used[100010],g[200010];
long long ans,s1;

int fpow(int i,int j)
{int ret=1;
 for(;j;i=(ll)i*i%mod,j/=2)
 	if(j&1) ret=(ll)ret*i%mod;
 return ret;
}

void add(int u,int v,int c)
{e[num].u=u;
 e[num].v=v;
 e[num].c=c;
 e[num].next=head[u];
 head[u]=num;
 num++;
 e[num].u=v;
 e[num].v=u;
 e[num].c=c;
 e[num].next=head[v];
 head[v]=num;
 num++;
}

void get_root(int i,int fa)
{int j;
 
 f[i].size=1;
 f[i].ms=0;
 j=head[i];
 while(j!=-1)
 {	if(used[e[j].v]==0 && e[j].v!=fa)
 	{	get_root(e[j].v,i);
 		f[i].size+=f[e[j].v].size;
 		f[i].ms=max(f[i].ms,f[e[j].v].size);
 	}
 	j=e[j].next;
 }
 f[i].ms=max(f[i].ms,size-f[i].size);
 if(!root || f[i].ms<f[root].ms)
 	root=i;
}

void dfs1(int i,int fa,int l,int s)
{int j;
 
 f[i].size=1;
 s%=mod;
 g[++cnt]=s;
 //cout<<"BB "<<i<<" "<<l<<" "<<s<<endl;
 j=head[i];
 while(j!=-1)
 {	if(e[j].v!=fa && !used[e[j].v])
 	{	dfs1(e[j].v,i,l+1,(s+(ll)pw[l]*e[j].c)%mod);
 		f[i].size+=f[e[j].v].size;
 	}
 	j=e[j].next;
 }
}

void dfs2(int i,int fa,int l,int s)
{int j,x,ret=0;
 
 x=(ll)(mod-s)*ipw[l]%mod;
 x=(x%mod+mod)%mod;
 s1=(s1+(lower_bound(g+1,g+cnt+1,x+1)-lower_bound(g+1,g+cnt+1,x)));
 //cout<<"cc "<<i<<" "<<s<<" "<<l<<" "<<x<<" "<<s1<<endl;
 j=head[i];
 while(j!=-1)
 {	if(e[j].v!=fa && !used[e[j].v])
 		dfs2(e[j].v,i,l+1,((ll)s*10+e[j].c)%mod);
 	j=e[j].next;
 }
}

void solve(int i)
{int j;
 
 used[i]=1;
 j=head[i];
 while(j!=-1)
 {	if(!used[e[j].v])
 	{	cnt=0;
 		g[++cnt]=-1;
 		g[++cnt]=mod;
	 	dfs1(e[j].v,i,1,e[j].c%mod);
 		sort(g+1,g+cnt+1);
 		s1=0;
		dfs2(e[j].v,i,1,e[j].c%mod);
		ans=(ans-s1);
		//cout<<"## "<<i<<" "<<e[j].v<<" "<<s1<<endl;
 	}
 	j=e[j].next;
 }
 j=head[i];
 cnt=0;
 g[++cnt]=-1;
 g[++cnt]=0;
 g[++cnt]=mod;
 while(j!=-1)
 {	if(!used[e[j].v])
 		dfs1(e[j].v,i,1,e[j].c%mod);
 	j=e[j].next;
 }
 sort(g+1,g+cnt+1);
 //for(j=1;j<=cnt;j++) cout<<g[j]<<" ";
 //cout<<endl;
 j=head[i];
 while(j!=-1)
 {	if(!used[e[j].v])
 	{	s1=0;
 		dfs2(e[j].v,i,1,e[j].c%mod);
 		ans=(ans+s1);
 	}
	j=e[j].next;
 }
 //cout<<"kk "<<ans<<endl;
 ans=(ans+(lower_bound(g+1,g+cnt+1,1)-g)-2);

 j=head[i];
 while(j!=-1)
 {	if(!used[e[j].v])
 	{	size=f[e[j].v].size;
 		root=0;
 		get_root(e[j].v,i);
 		solve(root);
 	}
 	j=e[j].next;
 }
}
 
int main()
{int i,j,x,y,z;
 
 scanf("%d%d",&n,&mod);
 memset(head,-1,sizeof(head));
 for(i=1;i<n;i++)
 {	scanf("%d%d%d",&x,&y,&z);
 	x++;
 	y++;
	add(x,y,z);
 }
 x=mod;
 y=mod;
 for(i=2;i*i<=mod;i++)
 {	if(mod%i!=0) continue;
 	if(x%i==0)
 	{	while(x%i==0) x/=i;
 		y=y/i*(i-1);
 	}
 }
 if(x>1) y=y/x*(x-1);
 
 x=fpow(10,y-1);
 pw[0]=1;
 for(i=1;i<=n;i++) pw[i]=(ll)pw[i-1]*10%mod;
 ipw[0]=1;
 for(i=1;i<=n;i++) ipw[i]=(ll)ipw[i-1]*x%mod;
 size=n;
 get_root(1,0);
 solve(root);
 ans-=n;
 cout<<ans<<endl;
 return 0;
}