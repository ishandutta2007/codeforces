#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
const int N=200050;
const int M=1050000;
const int U=5*M;
vector<int> Div[N];
int go[U];
void cut(int x, int id)
{
	int c=0,p=0;
	while(x>1)
	{
		if(go[x]!=p){ if(c&1) Div[id].pb(p);c=0;}
		c++;p=go[x];x/=go[x];
	}
	if(c&1) Div[id].pb(p);
}
int sol[20],a[N],ans[M],las[8][U];
vector<pair<int,int> > Qs[N];
int main()
{
	int n,i,j,q,l,r,k;
	for(i=2;i<U;i++)
	{
		if(!go[i])
		{
			for(j=i;j<U;j+=i) go[j]=i;
		}
	}
	scanf("%i %i",&n,&q);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),cut(a[i],i);
	for(i=1;i<=q;i++) scanf("%i %i",&l,&r),Qs[r].pb(mp(l,i));
	for(i=1;i<=n;i++)
	{
		int sz=Div[i].size();
		for(j=0;j<1<<sz;j++)
		{
			int b=1,c=0;
			for(k=0;k<sz;k++) if((j>>k)&1) b*=Div[i][k],c++;
			for(k=0;k<=7;k++)
			{
				sol[k+sz-2*c]=max(sol[k+sz-2*c],las[k][b]);
			}
			las[sz][b]=i;
		}
		for(j=0;j<Qs[i].size();j++)
		{
			for(k=19;~k;k--) if(sol[k]>=Qs[i][j].first) ans[Qs[i][j].second]=k;
		}
	}
	for(i=1;i<=q;i++) printf("%i\n",ans[i]);
	return 0;
}