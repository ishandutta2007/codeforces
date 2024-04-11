#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=200050;
struct compress
{
	vector<int> id;
	compress(){}
	void Add(int x){ id.pb(x);}
	void Build()
	{
		sort(id.begin(),id.end());
		id.resize(unique(id.begin(),id.end())-id.begin());
	}
	int Get(int x){ return lower_bound(id.begin(),id.end(),x)-id.begin()+1;}
} XC,YC;
vector<pair<int,int>> ys[N];
int x[N],y[N],L[N],LL[N],R[N],cnt[N];
int sve[N];
const int M=2*N;
struct SegmentTree
{
    int sum[M];
    void init(){ for(int i=0;i<M;i++) sum[i]=0;}
    SegmentTree(){ init();}
    void Set(int i, int f){ for(i+=N;i;i>>=1) sum[i]+=f;}
    int Get(int l, int r)
    {
        int ans=0;
        for(l+=N,r+=N;l<=r;l>>=1,r>>=1)
		{
			if(l%2==1) ans+=sum[l++];
			if(r%2==0) ans+=sum[r--];
		}
		return ans;
    }
} ST;
int main()
{
	int n;
	scanf("%i",&n);
	for(int i=1;i<=n;i++) scanf("%i %i",&x[i],&y[i]),XC.Add(x[i]),YC.Add(y[i]);
	XC.Build();
	YC.Build();
	for(int i=1;i<=n;i++)
	{
		x[i]=XC.Get(x[i]);
		y[i]=YC.Get(y[i]);
        ys[x[i]].pb({y[i],i});
	}
	ST.init();
	for(int i=1;i<=XC.id.size();i++)
	{
        sort(ys[i].begin(),ys[i].end());
		for(int j=0;j<ys[i].size();j++)
		{
			int id=ys[i][j].second;
			int Y=ys[i][j].first;
			L[id]=ST.Get(Y,YC.id.size())-cnt[Y]-sve[Y];
			LL[id]=cnt[Y]+sve[Y];
			sve[Y]+=L[id];
			cnt[Y]++;
		}
        ST.Set(ys[i].back().first,1);
	}
	ST.init();
	for(int i=0;i<N;i++) cnt[i]=0;
	for(int i=XC.id.size();i>=1;i--)
	{
        sort(ys[i].begin(),ys[i].end());
		for(int j=0;j<ys[i].size();j++)
		{
			int id=ys[i][j].second;
			int Y=ys[i][j].first;
			R[id]=ST.Get(Y,YC.id.size())-cnt[Y];
			cnt[Y]++;
		}
        ST.Set(ys[i].back().first,1);
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=(ll)(L[i]+1)*(R[i]+1);
		ans+=LL[i];
		//printf("%i %i\n",L[i],R[i]);
	}
	printf("%lld\n",ans);
	return 0;
}