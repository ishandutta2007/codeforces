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
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 1000005
int n,C,mx[N],a[N],ans[N],Q;
signed main()
{
	cin>>n>>C;
	for(int i=1;i<=n;i++)
	{
		int c=read(),v=read()*read();
		a[c]=max(a[c],v);
	}
	for(int i=1;i<=C;i++) if(a[i])
	{
		for(int j=i;j<=C;j+=i)
		{
			mx[j]=max(mx[j],a[i]*(j/i));
		}
	}
	for(int i=1;i<=C;i++) mx[i]=max(mx[i-1],mx[i]);
	// for(int i=1;i<=C;i++) printf("%d%c",mx[i]," \n"[i==C]);
	mx[C+1]=INF;
	cin>>Q;
	while(Q--)
	{
		int v=read()*read();
		int ans=upper_bound(mx+1,mx+C+2,v)-mx;
		if(ans>C) printf("-1 ");
		else printf("%lld ",ans);
	}
	return 0;
}