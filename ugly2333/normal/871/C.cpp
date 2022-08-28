//CF 871C
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
const int mod = 1e9+7;
int x[N],y[N];
int mx[N],my[N];
map<int,int> M;
int vis[2*N];
vector<int> v[2*N];
int cnt[2*N];
pair<int,int> dfs(int u){
	int i,s,x;
	pair<int,int> res,t;
	vis[u]=1;
	res=make_pair(1,cnt[u]);
	s=v[u].size();
	for(i=0;i<s;i=i+1){
		x=v[u][i];
		if(!vis[x]){
			t=dfs(x);
			res.first+=t.first;
			res.second+=t.second;
		}
	}
	return res;
}
int fpow(int q,int w){
	LL res;
	if(w==0)
		return 1;
	res=fpow(q,w/2);
	res=res*res%mod;
	if(w&1)
		res=res*q%mod;
	return res;
}
int calc(int n,int m)
{
	int i;
	LL c,res;
	res=1;
	c=1;
	for(i=1;i<=m;i=i+1){
		c=c*(n-i+1)%mod;
		c=c*fpow(i,mod-2)%mod;
		res+=c;
		res%=mod;
	}
	return res;
}
int main()
{
	int n,i,m;
	LL ans;
	pair<int,int> p;
	scanf("%d",&n);
	m=0;
	for(i=1;i<=n;i=i+1){
		scanf("%d%d",x+i,y+i);
		if(M.find(x[i]-mod)==M.end())
			M[x[i]-mod]=++m;
		if(M.find(y[i]+mod)==M.end())
			M[y[i]+mod]=++m;
		mx[i]=M[x[i]-mod];
		my[i]=M[y[i]+mod];
		//cout<<mx[i]<<my[i]<<endl;
		v[mx[i]].push_back(my[i]);
		v[my[i]].push_back(mx[i]);
		cnt[mx[i]]++;
		cnt[my[i]]++;
	}
	ans=1;
	for(i=1;i<=m;i=i+1)
		if(!vis[i]){
			p=dfs(i);
			//cout<<p.first<<p.second<<endl;
			ans=ans*calc(p.first,p.second/2)%mod;
		}
	cout<<ans<<endl;
	return 0;
}