#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=1050;
const int M=N*N;
const int mod=998244353;
int pow(int x, int k)
{
	int ret=1;
	for(;k;k>>=1,x=(ll)x*x%mod) if(k&1) ret=(ll)ret*x%mod;
	return ret;
}
int inv(int x){ return pow(x,mod-2);}
int a[N][N];
void ck(int &x){ while(x>=mod) x-=mod;while(x<0) x+=mod;}
vector<int> id;
int Find(int x){ return lower_bound(id.begin(),id.end(),x)-id.begin();}
struct SegmentTree
{
	vector<int> sum;
	int sz;
	SegmentTree(){}
	void init(int n){ sz=n;sum.resize(2*n);}
	void Set(int l, int r, int f)
	{
		for(l+=sz,r+=sz;l<=r;l>>=1,r>>=1)
		{
			if(l%2==1) sum[l]+=f,ck(sum[l]),l++;
			if(r%2==0) sum[r]+=f,ck(sum[r]),r--;
		}
	}
	int Get(int i){ int ret=0;for(i+=sz;i;i>>=1) ret+=sum[i],ck(ret);return ret;}
} ST;
int addx,mulx,addy,muly,dnt,cnt[M],sol[N][N],prob[M];
vector<pair<int,int> > my[M];
int main()
{
	int n,i,j,m,r,c;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) scanf("%i",&a[i][j]),id.pb(a[i][j]);
	scanf("%i %i",&r,&c);
	sort(id.begin(),id.end());id.erase(unique(id.begin(),id.end()),id.end());
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) a[i][j]=Find(a[i][j]),cnt[a[i][j]]++,my[a[i][j]].pb(mp(i,j));
	int sz=id.size();ST.init(sz);
	for(i=1;i<sz;i++) cnt[i]+=cnt[i-1];
	ST.Set(a[r][c],a[r][c],1);
	bool f=1;
	for(i=a[r][c];i>=0;i--)
	{
		int lo=0;
		if(i>0) lo=cnt[i-1];
		int pro=ST.Get(i);prob[i]=pro;
		if(!lo) break;
		int add=(ll)pro*inv(lo)%mod;
		if(!f) add=(ll)add*(cnt[i]-lo)%mod;
		ST.Set(0,i-1,add);
		f=0;
	}
	for(i=0;i<sz;i++)
	{
		for(auto p:my[i])
		{
			int tmp=addx+addy;ck(tmp);
			tmp+=(ll)p.first*p.first%mod*dnt%mod;ck(tmp);
			tmp+=(ll)p.second*p.second%mod*dnt%mod;ck(tmp);
			tmp-=(ll)p.first*mulx%mod;ck(tmp);
			tmp-=(ll)p.second*muly%mod;ck(tmp);
			sol[p.first][p.second]=tmp;
		}
		for(auto p:my[i])
		{
			addx+=(ll)p.first*p.first%mod;ck(addx);
			addy+=(ll)p.second*p.second%mod;ck(addy);
			mulx+=(ll)2*p.first%mod;ck(mulx);
			muly+=(ll)2*p.second%mod;ck(muly);
			dnt++;
		}
	}
	int res=0;
	for(i=1;i<=n;i++) for(j=1;j<=m;j++)
	{
		//printf("(%i %i) sol:%i prob:%i\n",i,j,sol[i][j],prob[a[i][j]]);
        if(a[i][j]<a[r][c] && a[i][j]>0) res+=(ll)sol[i][j]*inv(cnt[a[i][j]-1])%mod*prob[a[i][j]]%mod,ck(res);
	}
	if(a[r][c]>0) res+=(ll)sol[r][c]*inv(cnt[a[r][c]-1])%mod,ck(res);
	printf("%i\n",res);
	return 0;
}