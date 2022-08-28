//CF 
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
int n,l,w;
int tot,v[N<<1],h[N<<1],pr[N<<1],la[N];
void adde(int x,int y,int z){
	tot++;
	v[tot]=y;
	h[tot]=z;
	pr[tot]=la[x];
	la[x]=tot;
}
LL ans;
int t[N],isc[N];
int gett(int u,int fa=-1){
	int i,x;
	t[u]=1;
	for(i=la[u];i;i=pr[i]){
		x=v[i];
		if(x==fa||isc[x])
			continue;
		t[u]+=gett(x,u);
	}
	return t[u];
}
pair<int,int> fndc(int u,int tt,int fa=-1){
	int i,x,e;
	pair<int,int> res;
	e=tt-t[u];
	res=make_pair(N,0);
	for(i=la[u];i;i=pr[i]){
		x=v[i];
		if(x==fa||isc[x])
			continue;
		res=min(res,fndc(x,tt,u));
		e=max(e,t[x]);
	}
	return min(res,make_pair(e,u));
}
vector<pair<int,int> > cur,tmp;
void dfs(int u,int fa,int ww,int dd){
	int i,x;
	cur.push_back(make_pair(ww+1,dd+1));
	tmp.push_back(make_pair(ww+1,dd+1));
	for(i=la[u];i;i=pr[i]){
		x=v[i];
		if(x==fa||isc[x])
			continue;
		dfs(x,u,ww+h[i],dd+1);
	}
}
int T[N<<2];
void modify(int p,int x,int b){
	if(p<=0)
		return;
	while(p<=b){
		T[p]+=x;
		p+=p&-p;
	}
}
int query(int p,int b){
	if(p<0)
		return 0;
	if(p>b)
		p=b;
	int x=0;
	while(p){
		x+=T[p];
		p-=p&-p;
	}
	return x;
}
LL cnt(vector<pair<int,int> >& vv){
	int i,j,ww,dd,b;
	LL res=0;
	sort(vv.begin(),vv.end());
	reverse(vv.begin(),vv.end());
	b=vv.size();
	j=b-1;
	for(i=0;i<b;i=i+1){
		ww=vv[i].first,dd=vv[i].second;
		if(ww+ww<=w&&dd+dd<=l)
			res--;
		while(j>=0&&vv[j].first+ww<=w){
			modify(vv[j].second,1,b<<1);
			j--;
		}
		res+=query(l-dd,b<<1);
	}
	for(j=j+1;j<b;j=j+1)
		modify(vv[j].second,-1,b<<1);
	return res;
}
void solve(int u){
	int i,x;
	u=fndc(u,gett(u)).second;
	isc[u]=1;
	cur.clear();
	for(i=la[u];i;i=pr[i]){
		x=v[i];
		if(isc[x])
			continue;
		tmp.clear();
		dfs(x,u,h[i],1);
		ans-=cnt(tmp);
	}
	cur.push_back(make_pair(1,1));
	ans+=cnt(cur);
	for(i=la[u];i;i=pr[i]){
		x=v[i];
		if(isc[x])
			continue;
		solve(x);
	}
}
int main()
{
	int i,x,y;
	scanf("%d%d%d",&n,&l,&w);
	l+=2,w+=2;
	for(i=2;i<=n;i=i+1){
		scanf("%d%d",&x,&y);
		adde(i,x,y);
		adde(x,i,y);
	}
	solve(1);
	cout<<ans/2<<endl;
	return 0;
}