#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int L=22;
const int N=500050;
int Gauss[L],tme[L];
void Add(int x, int id)
{
	for(int i=L-1;~i;i--)
	{
		if((x>>i)&1)
		{
			if(Gauss[i])
			{
				if(tme[i]<id)
				{
					swap(Gauss[i],x);
					swap(tme[i],id);
				}
				x^=Gauss[i];
			}
			else
			{
				Gauss[i]=x;
				tme[i]=id;
				return;
			}
		}
	}
}
int Get(int id)
{
	int ans=0;
	for(int i=L-1;~i;i--) if(tme[i]>=id)
	{
		ans=max(ans,ans^Gauss[i]);
	}
	return ans;
}
int c[N];
vector<pair<int,int> > Qs[N];
int ans[N];
int main()
{
	int n,i,q,l,r;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&c[i]);
	scanf("%i",&q);
	for(i=1;i<=q;i++) scanf("%i %i",&l,&r),Qs[r].pb(mp(l,i));
	for(i=1;i<=n;i++)
	{
		Add(c[i],i);
		for(auto p:Qs[i]) ans[p.second]=Get(p.first);
	}
	for(i=1;i<=q;i++) printf("%i\n",ans[i]);
	return 0;
}