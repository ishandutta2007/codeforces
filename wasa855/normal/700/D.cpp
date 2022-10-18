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
#define N 100005
const int B=300,qwq=300;
int a[N],n,Q;
int ans[N],cnt[N],arr[N],pos[N];
struct Query{int l,r,id;};
Query q[N];
bool cmp(Query x,Query y)
{
	if(x.l/qwq==y.l/qwq)
	{
		if((x.l/qwq)&1) return x.r<y.r;
		else return x.r<y.r;
	}
	else return x.l<y.l;
}
void ins(int val)
{
	val=a[val];
	int v=cnt[val];
	arr[pos[v+1]+1]++,pos[v+1]++;
	cnt[val]++;
}
void del(int val)
{
	val=a[val];
	int v=cnt[val];
	arr[pos[v]]--,pos[v]--;
	cnt[val]--;
}
int b[305],c[305],d[305],m,sd;
int count()
{
	m=sd=0;
	for(int i=1;arr[i]>=B;i++) b[++m]=arr[i];
	for(int i=1;i<B;i++) c[i]=pos[i]-pos[i+1];
	int ans=0,ex=0;
	for(int i=1;i<B;i++)
	{
		if(!c[i]) continue;
		if(ex)
		{
			ans+=ex+i;
			if(ex+i>=B) d[++sd]=ex+i;
			else c[ex+i]++;
			c[i]--,ex=0;
		}
		if(c[i]&1) ex=i,c[i]--;
		ans+=i*c[i];
		if(i+i>=B)
		{
			for(int k=1;k<=c[i]/2;k++) d[++sd]=i+i;
		}
		else c[i+i]+=c[i]/2;
	}
	if(ex) b[++m]=ex;
	reverse(b+1,b+m+1);
	int i=1,j=1;
	while(m-i+1+sd-j+1>=2)
	{
		int A,B;
		if(j>sd||(i<=m&&b[i]<d[j])) A=b[i++];
		else A=d[j++];
		if(j>sd||(i<=m&&b[i]<d[j])) B=b[i++];
		else B=d[j++];
		ans+=A+B,d[++sd]=A+B;
	}
	return ans;
}
signed main()
{
	cin>>n; for(int i=1;i<=n;i++) a[i]=read();
	cin>>Q; for(int i=1;i<=Q;i++) q[i].l=read(),q[i].r=read(),q[i].id=i;
	sort(q+1,q+Q+1,cmp);
	int l=1,r=0;
	for(int i=1;i<=Q;i++)
	{
		while(r<q[i].r) ins(++r);
		while(l>q[i].l) ins(--l);
		while(r>q[i].r) del(r--);
		while(l<q[i].l) del(l++);
		ans[q[i].id]=count();
	}
	for(int i=1;i<=Q;i++) printf("%d\n",ans[i]);
	return 0;
}