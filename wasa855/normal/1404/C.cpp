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
#define N 300005
struct Query
{
	int x,y,id;
};
bool cmp(Query x,Query y)
{
	return x.x>y.x;
}
Query q[N];
int n,Q,a[N],ans[N];
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
const int S=500;
struct Block
{
	int v[S+5],tag,minn,len;
	void init(vector<int> &a)
	{
		len=a.size(); tag=0;
		for(int i=0;i<len;i++) v[i+1]=a[i];
		minn=inf;
		for(int i=1;i<=len;i++) minn=min(minn,v[i]);
	}
	void upd1(int v) // zheng kuai
	{
		tag+=v,minn+=v;
	}
	void upd2(int pl) // dan dian
	{
		for(int i=1;i<=len;i++) v[i]+=tag;
		tag=0;
		for(int i=pl+1;i<=len;i++) v[i]--;
		v[pl]=inf;
		minn=inf;
		for(int i=1;i<=len;i++) minn=min(minn,v[i]);
	}
}b[N/S+5];
int l[N],r[N],bl[N],m;
int qpl()
{
	for(int i=m;i>=1;i--)
	{
		if(b[i].minn==0)
		{
			for(int j=b[i].len;j>=1;j--)
			{
				if(b[i].v[j]+b[i].tag==0) return l[i]+j-1;
			}
		}
	}
	return 0;
}
void insert(int pl)
{
	while(1)
	{
		int r=qpl();
		if(r<pl) return ;
		// printf("%d %d\n",pl,r);
		bit.update(r,1);
		for(int i=bl[r]+1;i<=m;i++) b[i].upd1(-1);
		b[bl[r]].upd2(r-l[bl[r]]+1);
	}
}
signed main()
{
	cin>>n>>Q;
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=Q;i++)
	{
		q[i].x=read(),q[i].y=read(),q[i].id=i;
	}
	sort(q+1,q+Q+1,cmp);
	for(int i=1;i<=n;i++)
	{
		bl[i]=(i+S-1)/S;
		if(!l[bl[i]]) l[bl[i]]=i;
		r[bl[i]]=i;
	}
	m=bl[n];
	for(int i=1;i<=m;i++)
	{
		vector<int> ar;
		for(int j=l[i];j<=r[i];j++)
		{
			if(a[j]>j) ar.pb(inf);
			else ar.pb(j-a[j]);
		}
		b[i].init(ar);
	}
	int cur=n;
	bit.init(n);
	for(int i=1;i<=Q;i++)
	{
		while(q[i].x<cur) insert(cur--);
		ans[q[i].id]=bit.query(n-q[i].y);
		// printf("-- %d %d\n",q[i].id,ans[q[i].id]);
	}
	for(int i=1;i<=Q;i++) printf("%d\n",ans[i]);
	return 0;
}