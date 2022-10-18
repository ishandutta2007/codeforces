#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
#define ll long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
#define N 600005
int lowbit(int u){return u&(-u);}
int t[N],al[N],ar[N];
int id[N];
int lim;
void add(int u,int d)
{
	while(u<=lim)
	{
		t[u]+=d;
		u+=lowbit(u);
	}
}
int query(int u)
{
	int ans=0;
	while(u)
	{
		ans+=t[u];
		u-=lowbit(u);
	}
	return ans;
}
signed main()
{
	int n,Q;
	cin>>n>>Q;
	lim=n+Q;
	for(int i=1;i<=n;i++) al[i]=ar[i]=i;
	for(int i=1;i<=n;i++) add(i+Q,1),id[i]=i+Q;
	while(Q--)
	{
		int u=read();
		int R=query(id[u]);
		if(R>ar[u]) ar[u]=R;
		add(id[u],-1);
		id[u]=Q+1;
		al[u]=1;
		add(id[u],1);
	}
	for(int i=1;i<=n;i++)
	{
		int R=query(id[i]);
		if(R>ar[i]) ar[i]=R;
	}
	for(int i=1;i<=n;i++) printf("%d %d\n",al[i],ar[i]);
	return 0;
}