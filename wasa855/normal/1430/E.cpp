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
#define ll long long
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
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 200005
char s[N],t[N];
int a[N],b[N],cnt[N],n;
vector<int> v[N];
struct BIT
{
	int len,t[N];
	void init(int l){len=l,memset(t,0,sizeof(t));}
	inline int lowbit(int x){return x&(-x);}
	void update(int u,int v){for(int i=u;i<=len;i+=lowbit(i)) t[i]+=v;}
	int query(int u)
	{
		int ans=0;
		for(int i=u;i>0;i-=lowbit(i)) ans+=t[i];
		return ans;
	}
}bit;
signed main()
{
	cin>>n;
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) t[i]=s[n-i+1];
	for(int i=1;i<=n;i++) v[s[i]].pb(i);
	for(int i=n;i>=1;i--)
	{
		a[i]=v[t[i]].back();
		v[t[i]].pop_back();
	}
	bit.init(n);
	ll ans=0;
	for(int i=n;i>=1;i--)
	{
		ans+=bit.query(a[i]);
		bit.update(a[i],1);
	}
	cout<<ans<<endl;
	return 0;
}