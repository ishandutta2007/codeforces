#include<bits/stdc++.h>
using namespace std;

const long long inf=1000000000000000000ll;
int q[2000200],l,r,cnt,n,d,x,hd[2200],la[2200],f[2200],lo[2200];
struct node{int to,next,c,val;}e[2000010];
char s[1100];
bool inq[2200];
long long dis[2200];
vector<int> pa;

void add(int x,int y,int c,int val)
{
	e[++cnt]=(node){y,hd[x],c,-val},hd[x]=cnt;
	e[++cnt]=(node){x,hd[y],0,val},hd[y]=cnt;
}

bool spfa()
{
	dis[1]=0,inq[1]=1,f[1]=1000000000;
	for (int i=2; i<=(1<<d+1)+2; i++) dis[i]=inf,inq[i]=0;
	q[l=r=1]=1;
	while (l<=r)
	{
		x=q[l++],inq[x]=0;
		for (int i=hd[x]; i; i=e[i].next)
			if (e[i].c&&dis[e[i].to]>dis[x]+e[i].val)
			{
				dis[e[i].to]=dis[x]+e[i].val;
				la[e[i].to]=i,f[e[i].to]=min(f[x],e[i].c);
				if (!inq[e[i].to]) inq[e[i].to]=1,q[++r]=e[i].to;
			}
	}
	return dis[(1<<d+1)+2]!=inf;
}

bool findpath(int x)
{
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i^1].c&&e[i].to!=(x-(1<<d)))
		{
			e[i^1].c--,e[i].c++;
			if (e[i].to==(1<<d+1)+2) return 1;
			if (x!=1) pa.push_back(lo[(x-(1<<d)-2)^(e[i].to-2)]);
			x=e[i].to;
			for (int j=hd[x]; j; j=e[j].next) 
				if (e[j].to==x+(1<<d)) 
				{
					e[j].c++,e[j^1].c--;
					return findpath(e[j].to);
				}
		}
}

int main()
{
	scanf("%d%d",&d,&n),cnt=1;
	for (int i=0; i<d; i++) lo[1<<i]=i;
	add(1,2,2000,0);
	for (int i=0; i<(1<<d)-1; i++)
		for (int j=0; j<d; j++) if (!((i>>j)&1)) add(i+2+(1<<d),(i|(1<<j))+2,2000,-1);
	for (int i=1; i<=n; i++)
	{
		scanf("%s",s),x=0;
		for (int j=0; j<d; j++) x|=((s[j]-'0')<<j);
		add(x+2,x+2+(1<<d),1,1000000000);
	}
	for (int i=0; i<(1<<d); i++)
	{
		add(i+2,i+2+(1<<d),2000,0);
		add(i+2+(1<<d),(1<<d+1)+2,2000,-1);
	}
	long long ans=0;
	while (spfa())
	{
		x=(1<<d+1)+2;
		int F=f[x]; long long D=dis[x];
		if (D>0) break;
		while (x!=1) e[la[x]].c-=F,e[la[x]^1].c+=F,x=e[la[x]^1].to;
		ans+=D;
	}
	printf("%lld\n",ans=(((ans-1)%1000000000+1000000000)%1000000000));
	
	while (findpath(1))
	{
		//cerr<<ans<<endl;
		for (int i=0,sz=pa.size(); i<sz; i++) printf("%d ",pa[i]);
		ans-=pa.size();
		if (ans) printf("R "),ans--; else break;
		pa.clear();
	}
	puts("");
	return 0;
}