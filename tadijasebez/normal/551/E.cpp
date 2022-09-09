#include <stdio.h>
//#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
//#define map unordered_map
#define ll long long
const int N=500750;
const int S=710;
//map<ll,int> First[S],Last[S];//,BlockAns[S];
vector<pair<ll,int> > Block[S];
ll BlockAdd[S],a[N];
int n;
int min(int a, int b){ return a>b?b:a;}
int max(int a, int b){ return a>b?a:b;}
ll max(ll a, ll b){ return a>b?a:b;}
void Build(int B)
{
	BlockAdd[B]=0;
	int l=max(1,B*S),i;
	int r=min(n,B*S+S-1);
	//Last[B].clear();
	//First[B].clear();
	//BlockAns[B].clear();
	Block[B].clear();
	for(i=l;i<=r;i++) Block[B].push_back(make_pair(a[i],i));
	sort(Block[B].begin(),Block[B].end());
	/*{
		if(Last[B].count(a[i]))
		{
			//BlockAns[B][a[i]]=max(BlockAns[B][a[i]],i-Last[B][a[i]]);
			Last[B][a[i]]=i;
		}
		else
		{
			First[B][a[i]]=i;
			Last[B][a[i]]=i;
		}
	}*/
}
int main()
{
	int q,i,t,l,r;ll y;
	scanf("%i %i",&n,&q);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(i=0;i*S<=n;i++) Build(i);
	while(q--)
	{
		scanf("%i",&t);
		if(t==1)
		{
			scanf("%i %i %lld",&l,&r,&y);
			int L=l/S;
			int R=r/S;
			if(L==R)
			{
				for(i=max(L*S,1);i<min(L*S+S,n+1);i++) a[i]+=BlockAdd[L];
				for(i=l;i<=r;i++) a[i]+=y;
				Build(L);
			}
			else
			{
				for(i=L*S;i<L*S+S;i++) a[i]+=BlockAdd[L];
				for(i=l;i<L*S+S;i++) a[i]+=y;
				Build(L);
				for(i=L+1;i<R;i++) BlockAdd[i]+=y;
				for(i=R*S;i<R*S+S;i++) a[i]+=BlockAdd[R];
				for(i=R*S;i<=r;i++) a[i]+=y;
				Build(R);
			}
		}
		else
		{
			scanf("%lld",&y);
			int sol=0;
			//for(i=0;i*S<=n;i++) sol=max(sol,BlockAns[i][y-BlockAdd[i]]);
			int fir=N,las=0;
			for(i=0;i*S<=n;i++)
			{
				int id=lower_bound(Block[i].begin(),Block[i].end(),make_pair(y-BlockAdd[i],0))-Block[i].begin();
				//printf("%i ",id);
				if(id!=Block[i].size() && Block[i][id].first==y-BlockAdd[i]) fir=min(fir,Block[i][id].second);
				ll tmp=y-BlockAdd[i]+1;
				id=lower_bound(Block[i].begin(),Block[i].end(),make_pair(tmp,0))-Block[i].begin();
				id--;
				//printf("%i ",id);
				if(id>=0 && Block[i][id].first==y-BlockAdd[i]) las=max(las,Block[i][id].second);
				//if(First[i][y-BlockAdd[i]]) fir=min(fir,First[i][y-BlockAdd[i]]);
				//if(Last[i][y-BlockAdd[i]]) las=max(las,Last[i][y-BlockAdd[i]]);
				//sol=max(sol,First[i][y-BlockAdd[i]]-Last[i-1][y-BlockAdd[i-1]]);
			}
			//printf("%i %i\n",las,fir);
			sol=las-fir;
			if(las==0) printf("-1\n");
			else printf("%i\n",sol);
		}
	}
	return 0;
}