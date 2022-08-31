//??CF 852E
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
vector<int> v[N];
LL f[N],ans[N];
int n;
int fpow(int p,int x){
	if(x==0)
		return 1;
	if(x==1)
		return p;
	int r;
	r=fpow(p,x/2);
	r=(LL)r*r%mod;
	if(x&1)
		r=(LL)r*p%mod;
	return r;
}

void dfs1(int u,int fa){
	int i,s,x;
	s=v[u].size();
	f[u]=1;
	if(u!=n&&s==1||s<1)
		return;
	for(i=0;i<s;i=i+1){
		x=v[u][i];
		if(x!=fa){
			dfs1(x,u);
			f[u]=(LL)f[u]*f[x]%mod;
		}
	}
	f[u]=(LL)f[u]*2%mod;
}

void ch(int u,int x){
	int su,sx;
	su=v[u].size();
	sx=v[x].size();
	if(su==1){
		f[u]=1;
		return;
	}
	if(sx==1){
		f[x]=f[u]*2;
		return;
	}
	f[u]=((LL)f[u]*fpow(f[x],mod-2))%mod;
	f[x]=((LL)f[x]*f[u])%mod;
}
void dfs2(int u,int fa){
	int i,s,x;
	s=v[u].size();
	if(!ans[u])
		ans[u]=f[u];
	for(i=0;i<s;i=i+1){
		x=v[u][i];
		if(x!=fa){
			ch(u,x);
			dfs2(v[u][i],u);
			ch(x,u);
		}
	}
}
int main()
{
	int i,x,y;
	scanf("%d",&n);
	if(n==1){
		cout<<1<<endl;
		return 0;
	}
	if(n==2){
		cout<<4<<endl;
		return 0;
	}
	for(i=1;i<n;i=i+1){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs1(n,0);
	dfs2(n,0);
	x=0;
	for(i=1;i<=n;i=i+1)
		x=(LL)(x+ans[i])%mod;
	cout<<x%mod<<endl;
	return 0;
}