#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
struct Edge
{
	int to;
	int nxt;
}e[200005];
int n,m,edgenum,head[10005],top,d[10005],tot,to1[10005],to2[10005];
char s[10005],tmp[5],val[10005][6],type[10005];
map<int,int>mp,mp2;
int toint(char*s,int len)
{
	int ans=0;
	for(int i=1;i<=len;i++)
	  ans=ans*200+s[i];
	int x=mp[ans];
	if(x)return x;
	++tot;
	return mp[ans]=tot;
}
int toint2(char*s,int len)
{
	int ans=0;
	for(int i=1;i<=len;i++)
	  ans=ans*200+s[i];
	++tot;
	return mp[ans]=tot;
}
bool check(char*s,int len)
{
	int ans=0;
	for(int i=1;i<=len;i++)
	  ans=ans*200+s[i];
	return mp[ans];
}
void add(int u,int v)
{
	d[u]++;
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
bool flag[10005],set[10005];
int now=0;
bool check2(int node)
{
	if(set[node])
	{
		if(val[node][1]=='r'&&val[node][2]=='e'&&val[node][3]=='s'&&val[node][4]=='\0')return 1;
		return 0;
	}
	return 0;
}
int same[10005];
void newv(int node)
{
	node=same[node];
	if(set[node])
	{
		printf("%s",val[node]+1);
		return;
	}
	now++;
	val[node][1]=(char)(now/26/26/26+'a');
	val[node][2]=(char)(now/26/26%26+'a');
	val[node][3]=(char)(now/26%26+'a');
	val[node][4]=(char)(now%26+'a');
	val[node][5]='\0';
	while(check(val[node],4))
	{
		now++;
		val[node][1]=(char)(now/26/26/26+'a');
		val[node][2]=(char)(now/26/26%26+'a');
		val[node][3]=(char)(now/26%26+'a');
		val[node][4]=(char)(now%26+'a');
		val[node][5]='\0';
	}
	printf("%s",val[node]+1);
	set[node]=1;
}
int calc(int node)
{
	if(d[node]==0||flag[same[node]])return 0;
	node=same[node];
	flag[node]=1;
	return calc(to1[node])+calc(to2[node])+1;
}
int st;
void make(int node)
{
	if(d[node]==0||flag[same[node]])return;
	node=same[node];
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		make(to);
	}
	if(st==node)printf("res");
	else newv(node);
	printf("=");
	newv(to1[node]);
	putchar(type[node]);
	newv(to2[node]);
	printf("\n");
	flag[node]=1;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		m=(int)strlen(s+1);
		int node=0,last=0,val1=0,val2=0;
		char tt='a';
		for(int j=1;j<=m;j++)
		{
			if(s[j]=='=')last=j;
			if(s[j]=='#'||s[j]=='$'||s[j]=='^'||s[j]=='&')
			{
				tt=s[j];
				for(int k=last+1;k<j;k++)
				  tmp[k-last]=s[k];
				top=j-last-1;
				int v=toint(tmp,top);
				if(d[tot]==0&&v==tot)
				{
					set[tot]=1;
					for(int i=1;i<=top;i++)
					  val[tot][i]=tmp[i];
					val[tot][top+1]='\0';
				}
				if(val1==0)val1=v;
				else val2=v;
				last=j;
			}
		}
		for(int k=last+1;k<=m;k++)
		  tmp[k-last]=s[k];
		top=m-last;
		int v=toint(tmp,top);
		if(d[tot]==0&&v==tot)
		{
			set[tot]=1;
			for(int i=1;i<=top;i++)
			  val[tot][i]=tmp[i];
			val[tot][top+1]='\0';
		}
		if(val1==0)val1=v;
		else val2=v;
		for(int j=1;j<=m;j++)
		{
			if(s[j]=='=')
			{
				for(int k=1;k<j;k++)
				  tmp[k]=s[k];
				top=j-1;
				node=toint2(tmp,top);
				break;
			}
		}
		if(val1)add(node,val1);
		if(val2)add(node,val2);
		type[node]=tt;
	}
	tmp[1]='r',tmp[2]='e',tmp[3]='s';
	st=toint(tmp,3);
	for(int i=1;i<=tot;i++)
	{
		for(int hd=head[i];hd;hd=e[hd].nxt)
		{
			int&to=e[hd].to;
			while(d[to]==1)to=e[head[to]].to;
		}
	}
	for(int i=1;i<=tot;i++)
	{
		if(d[i]==2)
		{
			to2[i]=e[head[i]].to;
			to1[i]=e[e[head[i]].nxt].to;
		}
	}
	for(int i=1;i<=tot;i++)same[i]=i;
	while(d[st]==1)
	{
		if(d[e[head[st]].to]==0)
		{
			if(check2(e[head[st]].to))printf("0\n");
			else
			{
				printf("1\n");
				printf("res=");
				newv(e[head[st]].to);
				printf("\n");
			}
			return 0;
		}
		st=e[head[st]].to;
	}
	for(int i=1;i<=tot;i++)
	{
		if(d[i]==2)
		{
			int v=(same[to1[i]]*5000+same[to2[i]])*10+type[i]%10;
			int x=mp2[v];
			if(x)same[i]=same[x];
			else mp2[v]=i;
		}
	}
	st=same[st];
	memset(flag,0,sizeof(flag));
	printf("%d\n",calc(st));
	memset(flag,0,sizeof(flag));
	make(st);
	return 0;
}