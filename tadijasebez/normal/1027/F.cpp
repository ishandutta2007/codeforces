#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=2000050;
struct DSU
{
	int p[N],cyc[N],ok;
	void init(){ for(int i=0;i<N;i++) p[i]=i,cyc[i]=0;ok=1;}
	DSU(){ init();}
	int Find(int x){ return x==p[x]?x:p[x]=Find(p[x]);}
	void Union(int x, int y)
	{
		if(!ok) return;
		x=Find(x);y=Find(y);
		if(x==y){ if(cyc[x]) ok=0;cyc[x]=1;}
		else{ if(cyc[x] && cyc[y]) ok=0;p[y]=x;cyc[x]|=cyc[y];}
	}
} Matching;
vector<int> id;
int Find(int x){ return lower_bound(id.begin(),id.end(),x)-id.begin()+1;}
int a[N],b[N];
int main()
{
	int n,i;
	scanf("%i",&n);
	for(int i=1;i<=n;i++) scanf("%i %i",&a[i],&b[i]),id.pb(a[i]),id.pb(b[i]);
	sort(id.begin(),id.end());
	id.erase(unique(id.begin(),id.end()),id.end());
	for(int i=1;i<=n;i++) a[i]=Find(a[i]),b[i]=Find(b[i]);
	int sz=id.size(),top=sz,bot=1,ans=-1,mid;
	while(top>=bot)
	{
        mid=top+bot>>1;
        Matching.init();
        for(int i=1;i<=n;i++)
		{
			if(a[i]<=mid && b[i]<=mid) Matching.Union(a[i],b[i]);
			else if(a[i]<=mid) Matching.Union(a[i],a[i]);
			else if(b[i]<=mid) Matching.Union(b[i],b[i]);
			else Matching.ok=0;
		}
		if(Matching.ok) top=mid-1,ans=mid;
		else bot=mid+1;
	}
	if(ans==-1) printf("-1\n");
	else printf("%i\n",id[ans-1]);
	return 0;
}