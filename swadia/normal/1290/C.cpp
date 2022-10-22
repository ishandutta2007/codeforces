#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;

#define MAXN 610000
#define MAXM 410000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

vector<int> v[MAXN];
int n,k;
char s[MAXN];
int pa[MAXN<<1];
int size[MAXN<<1];
int choose[MAXN<<1];

int getpa(int x)
{
	return pa[x]==x ? x:pa[x]=getpa(pa[x]);
}

void merge(int x1,int x2)
{
	if (x1==x2)
		return;
	size[x1]+=size[x2];
	if (choose[x1]==-1 || choose[x2]==-1)
		choose[x1]=choose[x2]=-1;
	if (choose[x1]==1 || choose[x2]==1)
		choose[x1]=choose[x2]=1;
	pa[x2]=x1;
}

int main()
{
	cin>>n>>k;
	cin>>s;
	int x,y;
	for (int i=1;i<=k;i++)
	{
		pa[i]=i;
		pa[i+k]=i+k;
		size[i]=1;
		scanf("%d",&x);
		while (x--)
		{
			scanf("%d",&y);
			v[y].push_back(i);
		}
	}
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		if (v[i].size()==1)
		{
			if (s[i-1]=='0')
			{
				int f1=getpa(v[i][0]);
				int f0=getpa(v[i][0]+k);
				if (choose[f1]==1)
					ans-=size[f1];
				else if (choose[f0]==1)
					ans-=size[f0];
				else
					ans-=min(size[f1],size[f0]);
				choose[f1]=1;
				choose[f0]=-1;
				ans+=size[f1];
			}
			else
			{
				int f1=getpa(v[i][0]);
				int f0=getpa(v[i][0]+k);
				if (choose[f1]==1)
					ans-=size[f1];
				else if (choose[f0]==1)
					ans-=size[f0];
				else
					ans-=min(size[f1],size[f0]);
				choose[f1]=-1;
				choose[f0]=1;
				ans+=size[f0];
			}
		}
		if (v[i].size()==2)
		{
			if (s[i-1]=='0')
			{
				int f1=getpa(v[i][0]);
				int f0=getpa(v[i][0]+k);
				int g1=getpa(v[i][1]);
				int g0=getpa(v[i][1]+k);
				if (choose[f1]==1)
					ans-=size[f1];
				else if (choose[f0]==1)
					ans-=size[f0];
				else
					ans-=min(size[f1],size[f0]);
				if (f1!=g1 && f1!=g0)
				{
					if (choose[g1]==1)
						ans-=size[g1];
					else if (choose[g0]==1)
						ans-=size[g0];
					else
						ans-=min(size[g1],size[g0]);
				}
				//WRT(ans);
				merge(f1,g0);
				merge(f0,g1);
				f1=getpa(f1);
				f0=getpa(f0);
				g1=getpa(g1);
				g0=getpa(g0);
				if (choose[f1]==1)
					ans+=size[f1];
				else if (choose[f0]==1)
					ans+=size[f0];
				else
					ans+=min(size[f1],size[f0]);
			}
			else
			{
				int f1=getpa(v[i][0]);
				int f0=getpa(v[i][0]+k);
				int g1=getpa(v[i][1]);
				int g0=getpa(v[i][1]+k);
				if (choose[f1]==1)
					ans-=size[f1];
				else if (choose[f0]==1)
					ans-=size[f0];
				else
					ans-=min(size[f1],size[f0]);
				if (f1!=g1 && f1!=g0)
				{
					if (choose[g1]==1)
						ans-=size[g1];
					else if (choose[g0]==1)
						ans-=size[g0];
					else
						ans-=min(size[g1],size[g0]);
				}
				//WRT(ans);
				merge(f1,g1);
				merge(f0,g0);
				f1=getpa(f1);
				f0=getpa(f0);
				g1=getpa(g1);
				g0=getpa(g0);
				if (choose[f1]==1)
					ans+=size[f1];
				else if (choose[f0])
					ans+=size[f0];
				else
					ans+=min(size[f1],size[f0]);
			}
		}
		printf("%d\n",ans);
	}
	
	return ~~(0^_^0);
}