//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,avx,mmx,popcnt,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define db double
#define mp make_pair
#define pb push_back
const int N=100050;
const int M=4*N;
const db eps=1e-10;
const db inf=2e10+7;
bool eq(db a, db b){ return fabs(a-b)<=eps;}
vector<db> id;
int Find(db x)
{
	int top=(int)id.size()-1,bot=0,mid,ans=id.size();
	while(top>=bot)
	{
		mid=top+bot>>1;
		if(id[mid]>x || eq(id[mid],x)) ans=mid,top=mid-1;
		else bot=mid+1;
	}
	return ans+1;
}
int ls[M],rs[M],lzy[M],mx[M],tsz,root;
void Set(int &c, int ss, int se, int qs, int qe, int f)
{
	if(qs>qe || qs>se || ss>qe) return;
	if(!c) c=++tsz;
	if(qs<=ss && qe>=se){ lzy[c]+=f;mx[c]+=f;return;}
	int mid=ss+se>>1;
	Set(ls[c],ss,mid,qs,qe,f);
	Set(rs[c],mid+1,se,qs,qe,f);
	mx[c]=max(mx[ls[c]],mx[rs[c]])+lzy[c];
}
vector<pair<db,int> > event;
db xl[N],xr[N],yr[N],yl[N];
int l[N],r[N];
db projl(db x, int y){ return x-y;}
db projr(db x, int y){ return x+y;}
int n,x[N],y[N];
bool Try(db mid)
{
	event.clear();id.clear();
	int i;
	for(i=1;i<=tsz;i++) ls[i]=rs[i]=lzy[i]=mx[i]=0;
	tsz=root=0;
	//mnx[0][0]=-inf,mxx[0][0]=inf,mny[0][0]=-inf,mxy[0][0]=inf;
	for(i=1;i<=n;i++)
	{
		xl[i]=projl((db)x[i]-mid,y[i]);
		xr[i]=projl((db)x[i]+mid,y[i]);
		yl[i]=projr((db)x[i]-mid,y[i]);
		yr[i]=projr((db)x[i]+mid,y[i]);
		id.pb(yl[i]);
		id.pb(yr[i]);
		event.pb(mp(xl[i],i));
		event.pb(mp(xr[i],-i));
	}
	sort(id.begin(),id.end());
	vector<db> tmp;tmp.pb(id[0]);
	for(i=1;i<id.size();i++) if(!eq(id[i],tmp.back())) tmp.pb(id[i]);
	id=tmp;
	int lim=id.size();
	for(i=1;i<=n;i++) l[i]=Find(yl[i]),r[i]=Find(yr[i]),Set(root,1,lim,l[i],r[i],1);
	sort(event.begin(),event.end());
	int ac=0;
	for(auto p:event)
	{
		i=abs(p.second);
        if(p.second>0) Set(root,1,lim,l[i],r[i],-1),ac++;
        else Set(root,1,lim,l[i],r[i],1),ac--;
        if(mx[root]+ac==n) return 1;
	}
	return 0;
}
multiset<int> st[2];
void Add(int t, int x){ st[t].insert(x);}
void Del(int t, int x){ st[t].erase(st[t].find(x));}
db Val(int t){ return st[t].empty()?0.0:(db)((*st[t].rbegin())-(*st[t].begin()))/2.0;}
int main()
{
	int i,mx=0,j=0;
	scanf("%i",&n);
	vector<pair<int,int> > work;
	for(i=1;i<=n;i++) scanf("%i %i",&x[i],&y[i]),work.pb(mp(x[i]+y[i],y[i]-x[i]));//,mx=max(mx,abs(x[i]-y[i]));
	db ans=inf;
    sort(work.begin(),work.end());
    for(i=0;i<n;i++) Add(1,work[i].second);
    for(i=0;i<n;i++)
	{
		while(j<n && (i==j || Val(0)<Val(1)))
		{
			ans=min(ans,max(Val(0),Val(1)));
			//printf(":D\n");
			Del(1,work[j].second);Add(0,work[j].first);
			j++;
		}
		ans=min(ans,max(Val(0),Val(1)));
		Add(1,work[i].second);Del(0,work[i].first);
	}
	//db top=mx+5,bot=0,mid,ans=0;
	//while(fabs(top-bot)>=0.000001)
	//{
	//	mid=(top+bot)/2;
	//	if(Try(mid)) top=mid,ans=mid;
	//	else bot=mid;
	//}
	cout << fixed << setprecision(12) << ans << "\n";
	return 0;
}