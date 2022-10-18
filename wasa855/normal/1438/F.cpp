#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false)
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define fir first
#define sec second
#define mod 998244353
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define ll long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
#define N 1000005
int cnt[N];
int getrnd(int l,int r) {return rnd()%(r-l+1)+l;}
int query(int u,int v,int w)
{
	cout<<"? "<<u<<" "<<v<<" "<<w<<endl;
	int r=read();
	if(r==-1) exit(0);
	return r;
}
signed main()
{
	int n=(1<<read())-1;
	for(int i=1;i<=420;i++)
	{
		int u=getrnd(1,n),v=getrnd(1,n),w=getrnd(1,n);
		while(u==v||u==w||v==w) u=getrnd(1,n),v=getrnd(1,n),w=getrnd(1,n);
		cnt[query(u,v,w)]++;
	}
	int mx1=0,mx2=0;
	for(int i=1;i<=n;i++)
	{
		if(cnt[i]>cnt[mx1]) mx2=mx1,mx1=i;
		else if(cnt[i]>cnt[mx2]) mx2=i;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(i!=mx1&&i!=mx2&&query(mx1,mx2,i)==i) ans=i;
	}
	cout<<"! "<<ans<<endl;
	return 0;
}