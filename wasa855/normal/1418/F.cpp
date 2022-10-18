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
#define N 200005
int n,m,L,R;
vector<int> d[N];
set<int> s;
int cnt[N],fr[N];
bool valid(int x1,int y1,int x2,int y2)
{
	if(x1*y1!=x2*y2) return 0;
	if(x1*y1<L||x1*y1>R) return 0;
	if(x1>x2||x2>n) return 0;
	if(y1<y2||y1>m) return 0;
	return 1;
}
signed main()
{
	cin>>n>>m>>L>>R;
	for(int i=1;i<N;i++) for(int j=i;j<N;j+=i) d[j].pb(i);
	int cl=1,cr=0;
	for(int x1=1;x1<=n;x1++)
	{
		int l=(L+x1-1)/x1,r=min(m,R/x1);
		if(l>r) {printf("-1\n"); continue;}
		while(cl>l)
		{
			cl--;
			for(int j:d[cl]) if(++cnt[j]==1) s.insert(j);
		}
		while(cr<r)
		{
			cr++;
			for(int j:d[cr]) if(++cnt[j]==1) s.insert(j);
		}
		while(cl<l)
		{
			for(int j:d[cl]) if(--cnt[j]==0) s.erase(j);
			cl++;
		}
		while(cr>r)
		{
			for(int j:d[cr]) if(--cnt[j]==0) s.erase(j);
			cr--;
		}
		bool ok=0;
		for(int a:d[x1])
		{
			auto pos=s.upper_bound(a);
			if(pos==s.end()) continue;
			int b=*pos;
			int x2=b*x1/a,y1=((l+b-1)/b)*b,y2=a*y1/b;
			// printf("-- %lld %lld %lld %lld\n",x1,y1,x2,y2);
			if(valid(x1,y1,x2,y2))
			{
				printf("%lld %lld %lld %lld\n",x1,y1,x2,y2);
				ok=1;
				break;
			}
		}
		if(!ok) printf("-1\n");
	}
	return 0;
}