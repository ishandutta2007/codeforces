#include <set>
#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define debug(x) //cerr<<#x<<'='<<x<<endl
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

template<typename T> void readii(T &x,T &y){read(x);read(y);}
template<typename T> void readiii(T &x,T &y,T &z){read(x);read(y);read(z);}
template<typename T> void read4i(T &x,T &y,T &z,T &w){read(x);read(y);read(z);read(w);}
const int N = 400040;
const int M = 100010;
struct LinkCut{
#define lrson(x) (x == ch[fa[x]][1])
#define isroot(x) (x!=ch[fa[x]][0] && x!=ch[fa[x]][1])
	int rev[N],ch[N][2],fa[N],sz[N],rsz[N],xsz[N];
	pii medg[N],edgv[N];
	void PullUp(int x){
		sz[x] = sz[ch[x][0]]+sz[ch[x][1]]+rsz[x]+xsz[x];
		medg[x] = max(medg[ch[x][0]],medg[ch[x][1]]);
		medg[x] = max(medg[x],edgv[x]);
	}
	void PushDown(int x){
		if(rev[x]){
			swap(ch[x][0],ch[x][1]);
			rev[ch[x][0]]^=1;rev[ch[x][1]]^=1;
			rev[x] = 0;
		}
	}
	void Update(int x){
		if(!isroot(x)) Update(fa[x]);
		PushDown(x);
	}
	void Rotate(int x){
		int cf = fa[x],lr = lrson(x);
		if(!isroot(cf)) ch[fa[cf]][lrson(cf)] = x;
		fa[x] = fa[cf]; fa[cf] = x;
		fa[ch[x][lr^1]] = cf;
		ch[cf][lr] = ch[x][lr^1];
		ch[x][lr^1] = cf;
		PullUp(cf);PullUp(x);
	}
	void Splay(int x){
		Update(x);
		while(!isroot(x)){
			int y = fa[x],z = fa[y];
			if(isroot(y)) Rotate(x);
			else{
				Rotate((lrson(z) == lrson(y))?y:x);
				Rotate(x);
			}
		}
	}
	void Access(int x){
		int cf = x;x = 0;
		while(cf){
			Splay(cf);
			xsz[cf]+=sz[x]-sz[ch[cf][1]];
			debug(x);
			debug(ch[cf][1]);
			debug(sz[x]-sz[ch[cf][1]]);
			ch[cf][1] = x;
			PullUp(cf);
			x = cf;
			cf = fa[x];
		}
	}
	inline void makeRoot(int x) {
		Access(x); Splay(x);
		rev[x] ^= 1;
	}
	void Link(int u,int v){
		makeRoot(u);
		makeRoot(v);
		fa[u] = v;
		xsz[v]+=sz[u];
		sz[v]+=sz[u];
	}
	void Cut(int u,int v){
		makeRoot(u);
		Access(v); Splay(u);
		ch[u][1] = 0;
		PullUp(u);
		fa[v] = 0;
	}
	int Find(int u){
		Access(u);Splay(u);
		int p = u;
		while(1){
			PushDown(p);
			if(!ch[p][0])break;
			p = ch[p][0];
		}
		Splay(p);
		return p;
	}
	int getsz(int u){
		debug(sz[u]);
		Access(u);
		debug(sz[u]);
		Splay(u);
		return sz[u];
	}
#undef lrson
#undef isroot
} LCT;

int n,m;
struct edg{
	int u,v,w;
	bool operator < (const edg &rhs) const{
		return w<rhs.w;
	}
}edges[N];

int main() {
	read(n);read(m);
	for(int i=0;i<N;i++){
		LCT.medg[i] = LCT.edgv[i] = make_pair(-1,-1);
	}
	for(int i=0;i<m;i++){
		read(edges[i].u);read(edges[i].v);read(edges[i].w);
	}
	int ans = 2e9,csu = n;

	multiset< pair<int,int> > cst;
	for(int ech=0;ech<m;ech++){
		int u = edges[ech].u,v = edges[ech].v,w = edges[ech].w;
		int a;
		if(u == v)continue;
		int cut = 0;
		
		if(LCT.Find(u) == LCT.Find(v)){
			LCT.makeRoot(u);
			LCT.Access(v);LCT.Splay(v);
			pii cc = LCT.medg[v];
			if(cc.first<w)goto nxt;
			LCT.Cut(cc.second,edges[cc.second-M].u);
			LCT.Cut(cc.second,edges[cc.second-M].v);
			cut = 1;
			cst.erase(cst.find(cc));
		}
		//cout<<"SZU"<<LCT.getsz(u)<<endl;
		//cout<<LCT.sz[u]<<' '<<LCT.rsz[u]<<' '<<LCT.xsz[u]<<'\n';
		//cout<<"SZV"<<LCT.getsz(v)<<endl;
		if(!cut){
			a = 0;
			if(LCT.getsz(u)%2 == 0)a+=1;
			if(LCT.getsz(v)%2 == 0)a+=1;
			if(a == 2)csu-=a;
		}
		//cout<<"Link"<<u<<' '<<v<<' '<<csu<<endl;
		LCT.sz[ech+M] = LCT.rsz[ech+M] = 1;
		LCT.edgv[ech+M] = LCT.medg[ech+M] = make_pair(w,ech+M);
		LCT.Link(u,ech+M);
		LCT.Link(v,ech+M);
		cst.insert(make_pair(w,ech+M));
	nxt:;
		if(csu == 0){
			/*cout<<"BEG"<<endl;
			cout<<LCT.Find(1)<<endl;
			cout<<LCT.Find(2)<<endl;
			cout<<LCT.Find(3)<<endl;
			cout<<LCT.Find(4)<<endl;
			cout<<LCT.getsz(LCT.Find(4))<<endl;*/
			while(1){
				pii cc = *cst.rbegin();
				LCT.Cut(cc.second,edges[cc.second-M].u);
				LCT.Cut(cc.second,edges[cc.second-M].v);
				//cout<<LCT.getsz(edges[cc.second-M].u)<<' '<<LCT.getsz(edges[cc.second-M].v)<<endl;
				if(LCT.getsz(edges[cc.second-M].u)%2==0 || LCT.getsz(edges[cc.second-M].v)%2==0){
					LCT.Link(cc.second,edges[cc.second-M].u);
					LCT.Link(cc.second,edges[cc.second-M].v);
					break;
				}
				//cout<<cc.first<<' '<<cc.second<<endl;
				cst.erase(--cst.end());
			}
			//cout<<"HOR"<<' '<<(*cst.rbegin()).first<<endl;
			ans = min(ans,(*cst.rbegin()).first);
		}
		if(ans == 2e9){
			cout<<-1;
		}else{
			cout<<ans;
		}
		cout<<'\n';
	}
	return 0;
}