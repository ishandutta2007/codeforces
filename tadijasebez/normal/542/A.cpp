#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=200050;
const int M=4*N;
const int inf=1e9+7;
pair<int,int> max(pair<int,int> a, pair<int,int> b){ return a>b?a:b;}
pair<int,int> BIT[M];
void Set(int i, pair<int,int> f){ for(;i;i-=i&-i) BIT[i]=max(BIT[i],f);}
pair<int,int> Get(int i){ pair<int,int> ret=mp(0,0);for(;i<M;i+=i&-i) ret=max(ret,BIT[i]);return ret;}
vector<int> id;
int Find(int x){ return lower_bound(id.begin(),id.end(),x)-id.begin()+1;}
int l[N],r[N],lid[N],rid[N],ql[N],qr[N],qld[N],qrd[N],qx[N],taj[N];
ll sol[N];
int Max[M],idx[M],Min[M];
vector<pair<pair<int,int> ,pair<int,int> > > events;
int main()
{
	int n,m,i;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++) scanf("%i %i",&l[i],&r[i]),id.pb(l[i]),id.pb(r[i]);
	for(i=1;i<=m;i++) scanf("%i %i %i",&ql[i],&qr[i],&qx[i]),id.pb(ql[i]),id.pb(qr[i]);
	sort(id.begin(),id.end());
	id.erase(unique(id.begin(),id.end()),id.end());
	for(i=1;i<=n;i++) lid[i]=Find(l[i]),rid[i]=Find(r[i]);
	for(i=1;i<=m;i++) qld[i]=Find(ql[i]),qrd[i]=Find(qr[i]);
	for(i=1;i<=n;i++)
	{
		if(Max[lid[i]]<rid[i])
		{
			idx[lid[i]]=i;
			Max[lid[i]]=rid[i];
		}
	}
	int sz=id.size();
	for(i=2;i<=sz;i++)
	{
		if(Max[i-1]>Max[i])
		{
			idx[i]=idx[i-1];
			Max[i]=Max[i-1];
		}
	}
	for(i=1;i<=m;i++)
	{
		if(Max[qld[i]]>qrd[i])
		{
			sol[i]=(ll)(qr[i]-ql[i])*qx[i];
			taj[i]=idx[qld[i]];
			//printf("Upd1*:%i -> %i : %i\n",i,taj[i],sol[i]);
		}
		else if(Max[qld[i]]>qld[i])
		{
			sol[i]=(ll)(id[Max[qld[i]]-1]-ql[i])*qx[i];
			taj[i]=idx[qld[i]];
			//printf("Upd1:%i -> %i : %i\n",i,taj[i],sol[i]);
		}
	}
	for(i=1;i<=sz;i++) Min[i]=inf,idx[i]=0;
	for(i=1;i<=n;i++)
	{
		if(Min[rid[i]]>lid[i])
		{
			idx[rid[i]]=i;
			Min[rid[i]]=lid[i];
		}
	}
	for(i=sz-1;i;i--)
	{
		if(Min[i+1]<Min[i])
		{
			idx[i]=idx[i+1];
			Min[i]=Min[i+1];
		}
	}
	for(i=1;i<=m;i++)
	{
		if(Min[qrd[i]]<qld[i])
		{
			int time=qr[i]-ql[i];
			if(sol[i]<(ll)time*qx[i])
			{
				sol[i]=(ll)time*qx[i];
				taj[i]=idx[qrd[i]];
				//printf("Upd2*:%i -> %i : %i\n",i,taj[i],sol[i]);
			}
		}
		else if(Min[qrd[i]]<qrd[i])
		{
			int time=qr[i]-id[Min[qrd[i]]-1];
			if(sol[i]<(ll)time*qx[i])
			{
				sol[i]=(ll)time*qx[i];
				taj[i]=idx[qrd[i]];
				//printf("Upd2:%i -> %i : %i\n",i,taj[i],sol[i]);
			}
		}
	}
	for(i=1;i<=n;i++) events.pb(mp(mp(rid[i],1),mp(lid[i],i)));
	for(i=1;i<=m;i++) events.pb(mp(mp(qrd[i],2),mp(qld[i],i)));
	sort(events.begin(),events.end());
	for(i=0;i<events.size();i++)
	{
		int R=events[i].first.first;
		int t=events[i].first.second;
		int L=events[i].second.first;
		int j=events[i].second.second;
		if(t==1)
		{
			int time=r[j]-l[j];
			Set(L,mp(time,j));
		}
		else
		{
			pair<int,int> tmp=Get(L);
			if(tmp.first)
			{
				if((ll)tmp.first*qx[j]>sol[j])
				{
					taj[j]=tmp.second;
					sol[j]=(ll)tmp.first*qx[j];
					//printf("Upd3:%i -> %i : %i\n",j,taj[j],sol[j]);
				}
			}
		}
	}
	ll ans=0;
	int ret=0;
	for(i=1;i<=m;i++)
	{
		if(sol[i]>ans)
		{
			ans=sol[i];
			ret=i;
		}
	}
	if(ans>0)
	{
		printf("%lld\n",ans);
		printf("%i %i\n",taj[ret],ret);
	}
	else printf("0\n");
	return 0;
}