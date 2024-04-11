#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ldb long double
#define mt meke_tuple
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}
const int N=1000050;
const int M=2*N;
struct SegTree
{
	ll sum[M];
	void init(){ for(int i=0;i<M;i++) sum[i]=0;}
	SegTree(){ init();}
	void Set(int i, ll f){ for(i+=N;i;i>>=1) sum[i]+=f;}
	ll Get(int l, int r)
	{
		ll ans=0;
		for(l+=N,r+=N;l<=r;l>>=1,r>>=1)
		{
			if(l%2==1) ans+=sum[l],l++;
			if(r%2==0) ans+=sum[r],r--;
		}
		return ans;
	}
} CNT,SUM,IDS;
int l[N],r[N],a[N],n,q;
ll ans[N];
int R[N];
vector<pair<int,int>> Qs[N];
void Solve()
{
	vector<int> S(n+5);
	int c=0;
	S[++c]=n+1;
	a[n+1]=n+1;
	for(int i=n;i;i--)
	{
		while(a[S[c]]<a[i]) c--;
		R[i]=S[c];
		S[++c]=i;
	}
	CNT.init();
	SUM.init();
	//IDS.init();
	for(int i=1;i<=n;i++) Qs[i].clear();
	for(int i=1;i<=q;i++) Qs[l[i]-1].pb(mp(i,-1));
	for(int i=1;i<=q;i++) Qs[r[i]].pb(mp(i,1));
	for(int i=1;i<=n;i++)
	{
		CNT.Set(R[i],1);
		SUM.Set(R[i],R[i]);
		//IDS.Set(R[i],i);
		for(auto Q:Qs[i])
		{
			int id=Q.first;
			int mul=Q.second;
			ll add=SUM.sum[1]-(ll)i*(i+1)/2;
			ll sub=SUM.Get(r[id]+2,N-1);
			//ll sid=IDS.Get(r[id]+2,N-1);
			int cnt=CNT.Get(r[id]+2,N-1);
			add-=sub;
			add+=(ll)(r[id]+1)*cnt;
			ans[id]+=add*mul;
			//printf("id:%i add:%lld\n",id,add*mul);
		}
	}
}
int main()
{
	int i;
	scanf("%i %i",&n,&q);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=1;i<=q;i++) scanf("%i",&l[i]);
	for(i=1;i<=q;i++) scanf("%i",&r[i]);
    Solve();
    reverse(a+1,a+1+n);
    for(i=1;i<=q;i++) l[i]=n-l[i]+1,r[i]=n-r[i]+1,swap(l[i],r[i]);
    Solve();
	for(i=1;i<=q;i++) printf("%lld ",ans[i]-(r[i]-l[i]+1));
	return 0;
}