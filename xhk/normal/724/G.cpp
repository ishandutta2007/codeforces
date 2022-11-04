#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int mod=1000000007;

struct edge
{int u,v,next;
 long long c;
};
struct edge e[1000010];

int n,m,num,ans,s,inv2;
int head[1000010],used[1000010];
long long dis[1000010];
long long w[110];
vector<int> g;

void add(int u,int v,long long c)
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

int fpow(int i,int j)
{int ret=1;
 for(;j;i=(ll)i*i%mod,j/=2)
 	if(j&1) ret=(ll)ret*i%mod;
 return ret;
}

void insert(long long x)
{int i,j;
 
 for(i=63;i>=0;i--)
 {	if((x&(1LL<<i))==0) continue;
	if(w[i])
		x^=w[i];
	else
	{	w[i]=x;
		break;
	}
 }
}

void dfs(int i,int fa)
{int j;
 
 s++;
 g.push_back(i);
 used[i]=1;
 j=head[i];
 while(j!=-1)
 {	if(e[j].v!=fa)
 	{	if(!used[e[j].v])
 		{	dis[e[j].v]=dis[i]^e[j].c;
 			dfs(e[j].v,i);
 		}
 		else
 			insert(dis[i]^dis[e[j].v]^e[j].c);
 	}
 	j=e[j].next;
 }
}

int main()
{int i,j,x,y,s1,ss,k;
 long long z,mx;
 
 scanf("%d%d",&n,&m);
 memset(head,-1,sizeof(head));
 for(i=1;i<=m;i++)
 {	scanf("%d%d%I64d",&x,&y,&z);
 	add(x,y,z);
 }
 //for(i=0;i<num;i++)
 //	cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].c<<endl;
 inv2=fpow(2,mod-2);
 for(i=1;i<=n;i++)
 {	if(used[i]) continue;
 	s=0;
 	memset(w,0,sizeof(w));
 	g.clear();
 	dfs(i,0);
 	s1=0;
 	mx=0;
 	for(j=63;j>=0;j--)	
	 	if(w[j])
		{	s1++;
			mx|=w[j];
		}
 	x=fpow(2,s1);
 	for(j=63;j>=0;j--)
 	{	if(mx&(1LL<<j))
 			ans=(ans+(ll)(1LL<<j)%mod*s%mod*(s-1)%mod*inv2%mod*x%mod*inv2%mod)%mod;
 		else
		{	ss=0;
			for(k=0;k<g.size();k++)
				if(dis[g[k]]&(1LL<<j)) ss++;
			ans=(ans+(ll)(1LL<<j)%mod*ss%mod*(s-ss)%mod*x%mod)%mod;
		}
		//cout<<i<<" "<<j<<" "<<s1<<" "<<x<<" "<<ans<<endl;
	}
 }
 printf("%d\n",ans);
 return 0;
}