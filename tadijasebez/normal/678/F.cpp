#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
const int N=300050;
const int H=2*N;
const int M=19*N;
const ll inf=9e18;
int ls[H],rs[H],root,tsz;
vector<pair<int,int> > lines[H];
void AddLine(int &c, int ss, int se, int qs, int qe, pair<int,int> line)
{
	if(qs>qe) return;
	if(!c) c=++tsz;
	if(qs>se || ss>qe) return;
	if(qs<=ss && qe>=se){ lines[c].pb(line);return;}
	int mid=ss+se>>1;
	AddLine(ls[c],ss,mid,qs,qe,line);
	AddLine(rs[c],mid+1,se,qs,qe,line);
}
vector<int> id;
void Swap(pair<int,int> &a, pair<int,int> &b)
{
	a.first^=b.first;b.first^=a.first;a.first^=b.first;
	a.second^=b.second;b.second^=a.second;a.second^=b.second;
}
ll max(ll a, ll b){ return a>b?a:b;}
struct LiChao
{
	int ls[M],rs[M],root[25],bck[25],tsz,sz,n;
	bool has[M];
	pair<int,int> line[M];
	LiChao(){}
	void Init(int _n){ n=_n;}
	void AddRoot(){ root[sz+1]=root[sz];sz++;bck[sz]=tsz;}
	void DelRoot(){ tsz=bck[sz];sz--;}
	ll Get(pair<int,int> line, int x){ return (ll)line.first*id[x-1]+line.second;}
	void AddLine(int p, int &c, int ss, int se, pair<int,int> x)
	{
		c=++tsz;ls[c]=ls[p];rs[c]=rs[p];has[c]=has[p];line[c]=line[p];
		if(!has[c]){ has[c]=1;line[c]=x;return;}
		ll A=Get(line[c],ss),B=Get(x,ss),C=Get(line[c],se),D=Get(x,se);
		if(A>=B && C>=D) return;
		if(A<=B && C<=D){ line[c]=x;return;}
		if(A<B) Swap(line[c],x);
		int mid=ss+se>>1;
		if(Get(line[c],mid)>=Get(x,mid)) AddLine(rs[p],rs[c],mid+1,se,x);
		else Swap(line[c],x),AddLine(ls[p],ls[c],ss,mid,x);
	}
	void AddLine(pair<int,int> x){ AddLine(root[sz],root[sz],1,n,x);}
	ll Get(int c, int ss, int se, int qi)
	{
		ll ans=-inf;
		if(has[c]) ans=Get(line[c],qi);
		if(ss==se) return ans;
		int mid=ss+se>>1;
		if(qi<=mid) return max(ans,Get(ls[c],ss,mid,qi));
		else return max(ans,Get(rs[c],mid+1,se,qi));
	}
	ll Get(int x){ return Get(root[sz],1,n,x);}
} Tree;
ll sol[N];
int cnt,qx[N];
void Solve(int c, int ss, int se)
{
	if(ss>cnt) return;
	Tree.AddRoot();
	int i;
	for(i=0;i<lines[c].size();i++) Tree.AddLine(lines[c][i]);
	if(ss==se)
	{
		if(ss<=cnt) sol[ss]=Tree.Get(qx[ss]);
		Tree.DelRoot();
		return;
	}
	int mid=ss+se>>1;
	Solve(ls[c],ss,mid);
	Solve(rs[c],mid+1,se);
	Tree.DelRoot();
}
pair<int,int> line[N];
int type[N],fir[N];
bool done[N];
int main()
{
	int n,i,p;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&type[i]);
		if(type[i]==1)
		{
			fir[i]=cnt+1;
			scanf("%i %i",&line[i].first,&line[i].second);
		}
		if(type[i]==3)
		{
			cnt++;
			scanf("%i",&qx[cnt]);
			id.pb(qx[cnt]);
		}
		if(type[i]==2)
		{
			scanf("%i",&p);
			done[p]=1;
			AddLine(root,1,N,fir[p],cnt,line[p]);
		}
	}
	for(i=1;i<=n;i++) if(type[i]==1 && !done[i]) AddLine(root,1,N,fir[i],cnt,line[i]);
	sort(id.begin(),id.end());
	id.erase(unique(id.begin(),id.end()),id.end());
	for(i=1;i<=cnt;i++) qx[i]=lower_bound(id.begin(),id.end(),qx[i])-id.begin()+1;
	Tree.Init(id.size());
	Solve(root,1,N);
	for(i=1;i<=cnt;i++)
	{
		if(sol[i]==-inf) printf("EMPTY SET\n");
		else printf("%lld\n",sol[i]);
	}
	return 0;
}