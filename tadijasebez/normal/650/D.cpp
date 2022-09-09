#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define mp make_pair
#define pb push_back
const int N=800050;
const int M=2*N;
int max(int a, int b){ return a>b?a:b;}
int x[M],ls[M],rs[M],tsz,root;
void Init(){ root=tsz=0;}
void Set(int &c, int ss, int se, int qi, int val)
{
	if(!c) c=++tsz,x[c]=ls[c]=rs[c]=0;
	x[c]=max(x[c],val);
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,val);
	else Set(rs[c],mid+1,se,qi,val);
}
int Get(int c, int ss, int se, int qs, int qe)
{
	if(qs>se || ss>qe || qs>qe) return 0;
	if(qs<=ss && qe>=se) return x[c];
	int mid=ss+se>>1;
	return max(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
}
int dp[N/2][2],a[N/2],sol[N/2],sec[N/2],cnt[N/2];
vector<pair<int,int> > Qs[N/2];
vector<int> id;
int Find(int x){ return lower_bound(id.begin(),id.end(),x)-id.begin()+1;}
int main()
{
	int n,q,i,j,x,y;
	scanf("%i %i",&n,&q);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),id.pb(a[i]);
	for(i=1;i<=q;i++)
	{
		scanf("%i %i",&x,&y);
		id.pb(y);
		Qs[x].pb(mp(y,i));
	}
	sort(id.begin(),id.end());
	id.erase(unique(id.begin(),id.end()),id.end());
	int sz=id.size();
	Init();
	int best=0;
	for(i=1;i<=n;i++)
	{
		a[i]=Find(a[i]);
		dp[i][0]=Get(root,1,sz,1,a[i]-1)+1;
		for(j=0;j<Qs[i].size();j++)
		{
			Qs[i][j].first=Find(Qs[i][j].first);
			sol[Qs[i][j].second]+=Get(root,1,sz,1,Qs[i][j].first-1);
		}
		Set(root,1,sz,a[i],dp[i][0]);
	}
	Init();
	for(i=n;i>=1;i--)
	{
		dp[i][1]=Get(root,1,sz,a[i]+1,sz)+1;
		for(j=0;j<Qs[i].size();j++)
		{
			sol[Qs[i][j].second]+=Get(root,1,sz,Qs[i][j].first+1,sz)+1;
		}
		Set(root,1,sz,a[i],dp[i][1]);
		best=max(best,dp[i][0]+dp[i][1]-1);
	}
	for(i=1;i<=n;i++) if(dp[i][0]+dp[i][1]-1==best) cnt[dp[i][0]]++;
	for(i=1;i<=n;i++)
	{
		int ans;
		if(dp[i][0]+dp[i][1]-1==best)
		{
			if(cnt[dp[i][0]]==1) ans=best-1;
			else ans=best;
		}
		else ans=best;
		for(j=0;j<Qs[i].size();j++)
		{
			sec[Qs[i][j].second]=ans;
		}
	}
	for(i=1;i<=q;i++) printf("%i\n",max(sol[i],sec[i]));
	return 0;
}