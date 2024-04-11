#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
const int N = 100010;

vector<ll> ans;
struct SplayTree{
	int rt = 0,tot = 0;
	int ch[N][2],sz[N],fa[N];
	ll lazy[N],val[N];
	int typ(int x){
		return x == ch[fa[x]][1];
	}
	void PullUp(int x){
		sz[x] = sz[ch[x][0]]+sz[ch[x][1]]+1;
	}
	void PushDown(int x){
		val[x]+=lazy[x];
		lazy[ch[x][0]]+=lazy[x];
		lazy[ch[x][1]]+=lazy[x];
		lazy[x] = 0;
	}
	void LinkUpdate(int x){
		if(fa[x])LinkUpdate(fa[x]);
		PushDown(x);
	}
	void Rotate(int x){
		int y = fa[x],z = fa[y],ct = typ(x);
		if(z) ch[z][typ(y)] = x; fa[x] = z;
		ch[y][ct] = ch[x][ct^1]; fa[ch[x][ct^1]] = y;
		ch[x][ct^1] = y; fa[y] = x;
		PullUp(y);PullUp(x);
	}
	void Splay(int x){
		LinkUpdate(x);
		while(fa[x]){
			int y = fa[x],z = fa[y];
			if(z) Rotate((typ(x) == typ(y))?y:x);
			Rotate(x);
		}
	}
	int fnd(int &pos,int f,int csz,ll v){
		if(!pos){
			int ret = pos = ++tot;
			lazy[ret] = ch[ret][0] = ch[ret][1] = 0;
			val[ret] = v*(csz+1); sz[ret] = 1; fa[ret] = f;
			if(f) PullUp(f);
			Splay(ret);
			return ret;
		}
		PushDown(pos);
		if((csz+sz[ch[pos][0]]+1)*v<val[pos]){
			return fnd(ch[pos][1],pos,csz+sz[ch[pos][0]]+1,v);
		}
		return fnd(ch[pos][0],pos,csz,v);
	}
	void OptAns(int pos,ll& pre){
		if(!pos)return;
		PushDown(pos);
		OptAns(ch[pos][0],pre);
		pre+=val[pos];
		ans.push_back(pre);
		OptAns(ch[pos][1],pre);
	}
}T;

ll n,a[100010];
int main() {
	//freopen("subsequence.in","r",stdin);
	//freopen("subsequence.out","w",stdout);
	read(n);
	
	ll pre = 0;
	for(int i=1;i<=n;i++){
		read(a[i]);
		T.rt = T.fnd(T.rt,0,0,a[i]);
		T.lazy[T.ch[T.rt][1]]+=a[i];
	}
	pre = 0;
	ll rans = 0;
	
	T.OptAns(T.rt,pre);
	for(auto ct:ans){
		rans = max(rans,ct);
	}
	cout<<rans<<endl;
	return 0;
}