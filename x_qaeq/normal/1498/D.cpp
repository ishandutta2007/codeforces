#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
int n,m,ds[100005],rs[100005];char v[100005];set<int>a;
struct edge{int to,nxt;}e[5000005];int et,head[100005];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
int main()
{
	read(n),read(m),a.insert(0),memset(rs,0x3f,sizeof(rs));
	for(int i=1,op,y;i<=n;i++)
	{
		ll x;read(op),read(x),read(y),memset(head,0,sizeof(head)),et=0;
		queue<int>q;memset(v,0,sizeof(v)),memset(ds,0x3f,sizeof(ds));
		int p=(x+99999)/100000;for(auto x:a) q.push(x),v[x]=1,ds[x]=0;
		for(int j=0;j<=m;j++)
		{
			ll k;if(op==1) k=p+j;else k=1ll*x*j,k=(k+99999)/100000;
			if(k<=m) adde(j,k);
		}
		while(!q.empty())
		{
			int x=q.front();q.pop();
			for(int i=head[x];i;i=e[i].nxt) if(!v[e[i].to])
				v[e[i].to]=1,ds[e[i].to]=ds[x]+1,q.push(e[i].to);
		}
		for(int j=0;j<=m;j++) if(ds[j]<=y&&v[j]) rs[j]=min(rs[j],i);
		for(int j=0;j<=m;j++) if(v[j]&&ds[j]<=y) a.insert(j);
	}
	for(int i=1;i<=m;i++) printf("%d%c",rs[i]>n+5?-1:rs[i],i==m?'\n':' ');
	return 0;
}