#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
const int N=50050;
const int M=N*22;
const int S=225;
const int inf=1e9;
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
int go[M][2],Max[M],Min[M],x[M],tsz,root1[2],root2[2];
void Init(){ for(int i=1;i<=tsz;i++) go[i][0]=go[i][1]=Max[i]=x[i]=0,Min[i]=inf;tsz=0;}
void Init(int &c){ for(int i=c;i<=tsz;i++) go[i][0]=go[i][1]=Max[i]=x[i]=0,Min[i]=inf;tsz=min(c-1,tsz);c=0;}
void Set(int &c, int X, int Y, int lvl, int t)
{
	if(!c) c=++tsz;
	x[c]++;
	if(t==1) Max[c]=max(Max[c],Y);
	else Min[c]=min(Min[c],Y);
	if(!(~lvl)) return;
	Set(go[c][(X>>lvl)&1],X,Y,lvl-1,t);
}
int Get(int c, int X, int Y, int lvl, int t)
{
	if(!(~lvl)) return 0;
	int g=((X>>lvl)&1)^1;
	if(t==1)
	{
		if(x[go[c][g]] && Max[go[c][g]]>Y) return Get(go[c][g],X,Y,lvl-1,t)+(1<<lvl);
		else return Get(go[c][g^1],X,Y,lvl-1,t);
	}
	else
	{
		if(x[go[c][g]] && Min[go[c][g]]<=Y) return Get(go[c][g],X,Y,lvl-1,t)+(1<<lvl);
		else return Get(go[c][g^1],X,Y,lvl-1,t);
	}
}
vector<pair<pair<int,int> ,int> > block[N];
int l[N],r[N],sol[N],a[N],sum[M];
int main()
{
	int n,m,i,j,k;
	for(i=1;i<M;i++) sum[i]=sum[i-1]^i,Min[i]=inf;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=1;i<=m;i++)
	{
		scanf("%i %i",&l[i],&r[i]);
		if(r[i]-l[i]+1<S)
		{
			Init();root1[0]=root1[1]=0;
			for(j=l[i];j<=r[i];j++)
			{
				Set(root1[0],sum[a[j]-1],a[j],20,0);
				Set(root1[1],sum[a[j]],a[j],20,1);
				sol[i]=max(sol[i],Get(root1[0],sum[a[j]],a[j],20,0));
				sol[i]=max(sol[i],Get(root1[1],sum[a[j]-1],a[j],20,1));
			}
		}
		else block[l[i]/S].pb(mp(mp(r[i],l[i]),i));
	}
	for(i=0;i*S<=n;i++)
	{
		Init();root2[0]=root2[1]=root1[0]=root1[1]=0;
		sort(block[i].begin(),block[i].end());
		int done=(i+1)*S,Best=0;
		for(j=0;j<block[i].size();j++)
		{
			int QL=block[i][j].first.second;
			int QR=block[i][j].first.first;
			int id=block[i][j].second;
			while(done<=QR)
			{
				Set(root2[0],sum[a[done]-1],a[done],20,0);
				Set(root2[1],sum[a[done]],a[done],20,1);
				Best=max(Best,Get(root2[0],sum[a[done]],a[done],20,0));
				Best=max(Best,Get(root2[1],sum[a[done]-1],a[done],20,1));
				done++;
			}
			sol[id]=Best;
			for(k=QL;k<(i+1)*S;k++)
			{
				Set(root1[0],sum[a[k]-1],a[k],20,0);
				Set(root1[1],sum[a[k]],a[k],20,1);
				sol[id]=max(sol[id],Get(root1[0],sum[a[k]],a[k],20,0));
				sol[id]=max(sol[id],Get(root1[1],sum[a[k]-1],a[k],20,1));
				sol[id]=max(sol[id],Get(root2[0],sum[a[k]],a[k],20,0));
				sol[id]=max(sol[id],Get(root2[1],sum[a[k]-1],a[k],20,1));
			}
			Init(root1[0]);root1[1]=root1[0]=0;
		}
	}
	for(i=1;i<=m;i++) printf("%i\n",sol[i]);
	return 0;
}