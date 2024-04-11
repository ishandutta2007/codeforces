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
#define N 25005
int a[N],pre[N],sufl[N],sufr[N],prel[N],prer[N],n,Q;
int ans;
int ok(int u,int v)
{
	if(a[u]<a[v]) return sufr[u]==v&&prel[v]==u;
	else return prer[u]==v&&sufl[v]==u;
}
void work(int l,int r)
{
	if(a[l]<a[r])
	{
		if(a[l]>a[prel[r]])
		{
			ans-=ok(l,sufr[l]),ans-=ok(prel[r],r);
			sufr[l]=r,prel[r]=l,ans++;
		}
	}
	else
	{
		if(a[r]>a[prer[l]])
		{
			ans-=ok(l,prer[l]),ans-=ok(sufl[r],r);
			prer[l]=r,sufl[r]=l,ans++;
		}
	}
}
signed main()
{
	cin>>n>>Q;
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) pre[i]=i;
	while(Q--)
	{
		int l=read(),r=read();
		for(int i=l;i<=r;i++) while(pre[i]>l) pre[i]--,work(pre[i],i);
		printf("%d\n",ans);
	}
	return 0;
}