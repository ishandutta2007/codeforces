// author: xay5421
// created: Fri Apr 30 16:01:25 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define X first
#define Y second
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long LL;
const int N=400005;
int n,ind,a[N],b[N],c[N],d[N],dep[N];
bool pd[N];
int pp,lnk[N],nxt[N*2],to[N*2],we[N*2];
void ae(int k1,int k2,int k3){
	D("ae %d %d %d\n",k1,k2,k3);
	to[++pp]=k2,we[pp]=k3,nxt[pp]=lnk[k1],lnk[k1]=pp;
}
map<pair<LL,LL>,int>mp;
int get(LL x,LL y){
	LL g=__gcd(x,y);
	x/=g,y/=g;
	if(mp.count(make_pair(x,y)))return mp[make_pair(x,y)];
	return mp[make_pair(x,y)]=++ind;
}
vector<pair<int,int> >res;
void ps(int k1,int k2){
	res.emplace_back(k1,k2);
}
bool dfs(int k1,int k2){
	dep[k1]=dep[k2]+1;
	int up=-1,lst=-1;
	for(int i=lnk[k1];i;i=nxt[i]){
		if(to[i]==k2&&up==-1){
			up=we[i];
		}else if(dep[to[i]]==0){
			if(dfs(to[i],k1)){
				if(lst==-1)lst=we[i];
				else ps(lst,we[i]),lst=-1;
			}
		}else if(dep[to[i]]<dep[k1]){
			if(lst==-1)lst=we[i];
			else ps(lst,we[i]),lst=-1;
		}
	}
	if(lst!=-1&&up!=-1){
		ps(up,lst);
		return 0;
	}
	return 1;
}
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
		int k1=get(1LL*(a[i]+b[i])*d[i],1LL*b[i]*c[i]);
		int k2=get(1LL*a[i]*d[i],1LL*(c[i]+d[i])*b[i]);
		ae(k1,k2,i),ae(k2,k1,i);
	}
	rep(i,1,ind)if(!dep[i])dfs(i,0);
	printf("%d\n",SZ(res));
	for(auto x:res)printf("%d %d\n",x.X,x.Y);
	return 0;
}