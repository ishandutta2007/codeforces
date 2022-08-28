//CF 724G
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
const int N = 111111;
const int Q = 60;
const int mod = 1e9+7;
int n,m,vis[N],pw[N];
LL d[N],r;
vector<pair<int,LL> > v[N];
vector<LL> t,p;
void dfs(int u,LL dd){
	int i,sz,x;
	LL z;
	if(vis[u]){
		dd^=d[u];
		r|=dd;
		p.push_back(dd);
		return;
	}
	vis[u]=1;
	d[u]=dd;
	t.push_back(dd);
	sz=v[u].size();
	for(i=0;i<sz;i=i+1){
		x=v[u][i].first;
		z=v[u][i].second;
		dfs(x,dd^z);
	}
}
void getf(){
	int h,i,j;
	LL w,z;
	h=p.size();
	m=0;
	for(j=Q;j>=0;j=j-1){
		w=(LL)1<<j;
		for(i=0;i<h;i=i+1)
			if(p[i]&w)
				break;
		if(i>=h)
			continue;
		m++;
		z=p[i];
		p[i]=w;
		for(i=i+1;i<h;i=i+1)
			if(p[i]&w)
				p[i]^=z;
	}
}
/*vector<LL> f,g;
void getf(){
	f.clear(),g.clear();
	int sz,i;
	LL x;
	sz=p.size();
	while(sz--){
		x=p[sz];
		for(i=0;i<m;i=i+1)
			if(x&g[i])
				x^=f[i];
		if(x){
			m++;
			f.push_back(x);
			g.push_back(x&-x);
		}
	}
}*/
int main()
{
	int i,j,k,x,y;
	LL z,s,s0,s1,w,ans,ss;
	scanf("%d%d",&n,&m);
	pw[0]=1;
	for(i=1;i<N;i=i+1)
		pw[i]=(pw[i-1]+pw[i-1])%mod;
	while(m--){
		scanf("%d%d%lld",&x,&y,&z);
		v[x].push_back(make_pair(y,z));
		v[y].push_back(make_pair(x,z));
	}
	ans=0;
	for(i=1;i<=n;i=i+1){
		if(vis[i])
			continue;
		m=0,r=0;
		t.clear();
		p.clear();
		dfs(i,0);
		getf();
		s=(LL)t.size();
		for(j=0;j<=Q;j=j+1){
			w=(LL)1<<j;
			s0=0,s1=0;
			for(k=0;k<s;k=k+1){
				if(t[k]&w)
					s1++;
				else
					s0++;
			}
			if(r&w){
				ss=(LL)s*(s-1)/2;
				ss=(LL)ss%mod*pw[m-1]%mod;
			}
			else{
				ss=(LL)s0*s1%mod;
				ss=(LL)ss*pw[m]%mod;
			}
			ans+=(LL)pw[j]*ss%mod;
			ans%=mod;
		}
	}
	cout<<ans<<endl;
	return 0;
}