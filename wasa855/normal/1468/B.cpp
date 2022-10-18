#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define fir first
#define sec second
#define mod 998244353
#define int long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%lld%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 200005
int a[N],sum[N],q[N],n,Q;
int fl[N],fr[N],ans[N];
struct Node
{
	int l,r,ned;
	bool operator < (const Node &x) const {return ned>x.ned||(ned==x.ned&&l<x.l);}
};
Node getv(int l,int r)
{
	int ned=(sum[r]-sum[l-1]-1)/(r-l+1);
	return (Node){l,r,ned};
}
set<Node> s;
signed main()
{
	cin>>n>>Q;
	for(int i=1;i<=n;i++) a[i]=read();
	a[++n]=-INF;
	for(int i=1;i<=Q;i++) q[i]=read();
	reverse(q+1,q+Q+1); q[0]=1e9;
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++) fl[i]=fr[i]=i;
	for(int i=1;i<=n;i++) s.insert(getv(i,i));
	int res=0;
	for(int i=1;i<=Q;i++)
	{
		while(!s.empty()&&s.begin()->ned>=q[i])
		{
			auto it=s.begin();
			int l=it->l,r=it->r;
			// printf("^ %d %d\n",l,r);
			int tl=r+1,tr=fr[tl];
			s.erase(it),s.erase(getv(tl,tr));
			fr[l]=tr,fl[tr]=l;
			s.insert(getv(l,tr));
			res=max(res,min(tr,n-1)-l);
		}
		ans[i]=res;
	}
	for(int i=Q;i>=1;i--) printf("%lld%c",ans[i]," \n"[i==1]);
	return 0;
}