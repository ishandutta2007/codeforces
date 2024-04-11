//CF 965E
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
typedef double DB;
const int N = 111111;
int n,l,tt;
char ch[N];
int m=1,a[N][27],f[N],d[N],s[N],tin[N],tout[N];
vector<int> v[N];
int build(int k,int i){
	if(!k)
		k=++m;
	if(i==l)
		s[k]=1;
	else
		a[k][ch[i]]=build(a[k][ch[i]],i+1);
	return k;
}
void dfs(int k){
	tin[k]=++tt;
	v[d[k]].push_back(k);
	int i;
	for(i=0;i<26;i=i+1){
		if(a[k][i]){
			f[a[k][i]]=k;
			d[a[k][i]]=d[k]+1;
			dfs(a[k][i]);
		}
	}
	tout[k]=tt;
}
int T[N<<2],w[N<<2];
void modify(int L,int R,int D,int k=1,int l=1,int r=m){
	if(L<=l&&r<=R){
		w[k]+=D;
		T[k]+=D;
		return;
	}
	int h=l+r>>1;
	if(L<=h)
		modify(L,R,D,k<<1,l,h);
	if(h<R)
		modify(L,R,D,k<<1|1,h+1,r);
	T[k]=w[k]+min(T[k<<1],T[k<<1|1]);
}
int query(int L,int R,int k=1,int l=1,int r=m){
	if(L<=l&&r<=R)
		return T[k];
	int h=l+r>>1,res=N;
	if(L<=h)
		res=min(res,query(L,R,k<<1,l,h));
	if(h<R)
		res=min(res,query(L,R,k<<1|1,h+1,r));
	return res+w[k];
}
int main()
{
	int i,x,y,ans=0;
	scanf("%d",&n);
	while(n--){
		scanf("%s",ch);
		l=strlen(ch);
		for(i=0;i<l;i=i+1)
			ch[i]-='a';
		build(1,0);
	}
	dfs(1);
	for(i=2;i<=m;i=i+1){
		if(!s[i])
			modify(tin[i],tout[i],1);
	}
	for(l=m;l;l=l-1){
		i=v[l].size();
		while(i--){
			x=v[l][i];
			modify(tin[x],tout[x],1);
			for(y=x;s[y];y=f[y]);
			if(y>1&&query(tin[y],tout[y])){
				modify(tin[y],tout[y],-1);
				s[y]=1;
			}
			else{
				modify(tin[x],tout[x],-1);
				ans+=d[x];
			}
		}
	}
	cout<<ans;
	return 0;
}