//CF1662F
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 1111111;
int n,p[N],s[N],t[N],w[N],a[N],f[N];
vector<int> v[N];
LL ans,ss;
bitset<N> b;
void dfs(int u,int fa,int d){
	ans+=d;
	int i,x;
	w[u]=1;
	for(i=0;i<v[u].size();i++){
		x=v[u][i];
		if(x!=fa)
			dfs(x,u,d+1),w[u]+=w[x];
	}
}
void go(int x,int y){
	int i;
	y++;
	y*=x;
	for(i=x;i<=n;i++)
		f[i]=f[i-x]+f[i];
	for(i=n;i>=y;i--)
		f[i]=f[i]>f[i-y];
	for(i=y-1;i>=0;i--)
		f[i]=f[i]>0;
}
int main()
{
	int i,x;
	scanf("%d",&n);
	for(i=2;i<=n;i++){
		scanf("%d",p+i);
		//p[i]=i-1;
		v[i].push_back(p[i]);
		v[p[i]].push_back(i);
	}
	for(i=n;i>=1;i--){
		s[i]++;
		t[i]=max(t[i],n-s[i]);
		s[p[i]]+=s[i];
		t[p[i]]=max(t[p[i]],s[i]);
	}
	x=1;
	for(i=1;i<=n;i++)
		if(t[i]<t[x])
			x=i;
	dfs(x,0,1);
	for(i=0;i<v[x].size();i++)
		a[w[v[x][i]]]++;
	b[0]=1;
	for(i=1;i<=n;i++)
		if(a[i]==1)
			b=b|(b<<i);
	for(i=0;i<=n;i++)
		f[i]=b[i];
	for(i=1;i<=n;i++)
		if(a[i]>1)
			go(i,a[i]);
	ss=0;
	for(i=1;i<=n-1;i++)
		if(f[i])
			ss=max(ss,(LL)i*(n-1-i));
	printf("%lld\n",ans+ss);
	return 0;
}