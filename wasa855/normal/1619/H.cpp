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
int a[N],rev[N],n,Q,jmp[N];
const int B=300;
vector<int> getpre(int x)
{
	vector<int> ans(1,x);
	for(int i=1;i<=B;i++) ans.pb(rev[ans[i-1]]);
	return ans;
}
vector<int> getsuf(int x)
{
	vector<int> ans(1,x);
	for(int i=1;i<=B;i++) ans.pb(a[ans[i-1]]);
	return ans;
}
signed main()
{
	cin>>n>>Q;
	for(int i=1;i<=n;i++) a[i]=read(),rev[a[i]]=i;
	for(int i=1;i<=n;i++)
	{
		jmp[i]=i; for(int j=1;j<=B;j++) jmp[i]=a[jmp[i]];
	}
	while(Q--)
	{
		int op=read(),x=read(),y=read();
		if(op==1)
		{
			swap(a[x],a[y]),swap(rev[a[x]],rev[a[y]]);
			vector<int> px=getpre(x),py=getpre(y),sx=getsuf(x),sy=getsuf(y);
			for(int i=0;i<B;i++) jmp[px[i]]=sx[B-i];
			for(int i=0;i<B;i++) jmp[py[i]]=sy[B-i];
			// for(int i=1;i<=n;i++) printf("%d%c",a[i]," \n"[i==n]);
			// for(int i=1;i<=n;i++) printf("%d%c",jmp[i]," \n"[i==n]);
		}
		else
		{
			int q=y/B; for(int i=1;i<=q;i++) x=jmp[x];
			q=y%B; for(int i=1;i<=q;i++) x=a[x];
			printf("%d\n",x);
		}
	}
	return 0;
}