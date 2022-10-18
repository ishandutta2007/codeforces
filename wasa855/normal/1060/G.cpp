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
#define N 100005
int n,m,Q,a[N],ans[N];
struct Query{int k,x,id;};
Query q[N];
bool cmp(Query x,Query y) {return x.x<y.x;}
struct BIT
{
	inline int lowbit(int x) {return x&(-x);}
	int t[N];
	void upd(int u,int v) {for(int i=u;i<=n;i+=lowbit(i)) t[i]+=v;}
	int qry(int u)
	{
		int ans=0;
		for(int i=u;i>=1;i-=lowbit(i)) ans+=t[i];
		return ans;
	}
	int getrk(int v)
	{
		int l=1,r=n,ans=1;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(qry(mid)>=v) ans=mid,r=mid-1;
			else l=mid+1;
		}
		return ans;
	}
}bit;
bool cmp2(Query x,Query y) {return x.k<y.k;}
signed main()
{
	cin>>n>>Q;
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=Q;i++)
	{
		int x=read(),k=read();
		if(x<a[1]) ans[i]=x;
		else q[++m]=(Query){k,x,i};
	}
	sort(q+1,q+m+1,cmp);
	for(int i=1;i<=n;i++) bit.upd(i,1);
	int cur=1.1e15,tim=0,pos=m;
	for(int i=n;i>=1;)
	{
		int go=(cur-a[i]+i-1)/i,to=cur-go*i;
		while(pos>=1&&q[pos].x>=to)
		{
			q[pos].k=tim+(cur-q[pos].x+i-1)/i-q[pos].k;
			q[pos].x=bit.getrk(i-(cur-q[pos].x+i-1)%i);
			pos--;
		}
		cur=to,tim+=go;
		while(i>=1&&a[i]>=cur)
		{
			int tmp=bit.getrk(a[i]-cur+1);
			bit.upd(tmp,-1);
			i--;
		}
	}
	sort(q+1,q+m+1,cmp2);
	// for(int i=1;i<=m;i++) printf("%lld %lld - %lld\n",q[i].x,q[i].k,q[i].id);
	for(int i=1;i<=n;i++) bit.upd(i,1);
	cur=1.1e15,tim=0,pos=1;
	for(int i=n;i>=1;)
	{
		int go=(cur-a[i]+i-1)/i,to=cur-go*i;
		while(pos<=m&&q[pos].k<=tim+go)
		{
			ans[q[pos].id]=cur+bit.qry(q[pos].x)-(q[pos].k-tim)*i-1;
			pos++;
		}
		cur=to,tim+=go;
		while(i>=1&&a[i]>=cur)
		{
			int tmp=bit.getrk(a[i]-cur+1);
			bit.upd(tmp,-1);
			i--;
		}
	}
	for(int i=1;i<=Q;i++) printf("%lld\n",ans[i]);
	return 0;
}