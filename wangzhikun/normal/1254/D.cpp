#include <set>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define debug(x) cerr<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

int mod = 998244353;
inline int mul(int x,int y){return 1ll*x*y%mod;}
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
int sq(int x){return 1ll*x*x%mod;}
int pow(int a,int b){return b == 0 ? 1 : ( b&1 ? mul(a,sq(pow(a,b/2))) : sq(pow(a,b/2)));}
int inv(int x) {
	return pow(x,mod-2);
}

const int maxn = 150050;


struct fenwick_tree{
	int c[maxn];
	inline void tadd(int x, int y){
		while (x <= 150000){
			c[x] = add(c[x],y);
			x += x & -x;
		}
	}
	inline int sum(int x){
		int res = 0;
		while (x > 0){
			res = add(res,c[x]);
			x -= x & -x;
		}
		return res;
	}
	inline void vadd(int l,int r,int v){
		tadd(l,v);
		tadd(r+1,mod-v);
	}
}A;

int tim = 0;
int n,q,d[150050],sz[150050],mson[150050],fa[150050],top[150050],dfn[150050],accu[150050],u,v;

vector<int> G[150050];

void dfs1(int num){
	sz[num] = 1;
	mson[num] = 0;
	for(auto ct:G[num]){
		if(ct == fa[num])continue;
		fa[ct] = num;
		dfs1(ct);
		sz[num]+=sz[ct];
		if(sz[ct]>sz[mson[num]])mson[num] = ct;
	}
}

void dfs2(int num){
	tim++;
	dfn[num] = tim;
	if(num == mson[fa[num]])top[num] = top[fa[num]];
	else top[num] = num;
	if(mson[num]==0)return;
	dfs2(mson[num]);
	for(auto ct:G[num]){
		if(ct == mson[num] || ct == fa[num])continue;
		dfs2(ct);
	}
}


int main() {
	read(n);read(q);
	int invn = inv(n);
	for(int i=1;i<n;i++){
		read(u);read(v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs1(1);
	dfs2(1);
	//cout<<233<<endl;
	for(int i=0;i<q;i++){
		int typ,v,d;
		read(typ);
		if(typ == 1){
			read(v);read(d);
			A.vadd(1,n,mul(d,mul(sz[v],invn)));
			A.vadd(dfn[v],dfn[v]+sz[v]-1,mod-mul(d,mul(sz[v],invn)));
			//cout<<233<<endl;
			if(mson[v]){
				//cout<<dfn[mson[v]]<<' '<<dfn[mson[v]]+sz[mson[v]]-1<<endl;
				A.vadd(dfn[mson[v]],dfn[mson[v]]+sz[mson[v]]-1,mul(d,mul(n-sz[mson[v]],invn)));
			}
			accu[v] = add(accu[v],d);
		}else{
			//cout<<234<<endl;
			read(v);
			int cv = add(A.sum(dfn[v]),accu[v]);
			while(1){
				v = top[v];
				if(v == 1)break;
				cv = add(cv,mul(accu[fa[v]],mul(n-sz[v],invn)));
				v = fa[v];
			}
			cout<<cv<<"\n";
		}
		//cout<<"FAed"<<endl;
	}
	return 0;
}

/*
 += n-sz[ct]
 
 */