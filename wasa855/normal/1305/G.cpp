#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
int mul(int x,int y){return 1LL*x*y%mod;}
#define N 400005
int siz[N],fa[N];
int ans;
int find(int u){return fa[u]==u?u:fa[u]=find(fa[u]);}
void merge(int u,int v,int w)
{
	if(!siz[u]||!siz[v]) return ;
	u=find(u),v=find(v);
	if(siz[u]&&siz[v]&&u!=v)
	{
		// printf("%d %d %d\n",u,v,w);
		ans+=(siz[u]+siz[v]-1)*w;
		fa[u]=v; siz[v]=1;
	}
}
signed main()
{
	int n=read();
	for(int i=0;i<N;i++) fa[i]=i;
	for(int i=1;i<=n;i++)
	{
		int u=read(); ans-=u;
		siz[u]++;
	}
	siz[0]++;
	// int C=0;
	for(int i=262144;i>=0;i--)
	{
		for(int j=(i-1)&i;j!=0;j=(j-1)&i)
		{
			// C++;
			if(j<(i^j)) break;
			merge(j,i^j,i);
		}
		merge(i,0,i);
		// cout<<ans<<endl;
	}
	// cout<<C<<endl;
	cout<<ans<<endl;
	return 0;
}