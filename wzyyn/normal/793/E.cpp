#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=5005;
int n,A,B,C,D;
int be[N],fa[N],sz[N];
vector<int> e[N];
bitset<N> bit;
int main(){
	scanf("%d",&n);
	scanf("%d%d%d%d",&A,&B,&C,&D);
	For(i,2,n){
		scanf("%d",&fa[i]);
		e[fa[i]].PB(i);
		be[i]=(fa[i]==1?i:be[fa[i]]);
	}
	Rep(i,n,1){
		if (e[i].size()==0) ++sz[i];
		if (fa[i]) sz[fa[i]]+=sz[i];
	}
	if (sz[1]&1) return puts("NO"),0;
	if (sz[be[A]]>=sz[1]/2||sz[be[B]]>=sz[1]/2||
		sz[be[C]]>=sz[1]/2||sz[be[D]]>=sz[1]/2)
			return puts("NO"),0;
	assert(be[A]!=be[B]);
	assert(be[A]!=be[C]);
	assert(be[A]!=be[D]);
	assert(be[B]!=be[C]);
	assert(be[B]!=be[D]);
	assert(be[C]!=be[D]);
	For(i,0,n) bit[i]=(i==0);
	for (int x=A,y=0;x;y=x,x=fa[x])
		for (auto j:e[x]) if (j!=y)
			if (j!=be[A]&&j!=be[B]&&j!=be[C]&&j!=be[D])
				bit|=bit<<sz[j];
	for (int x=B,y=0;x!=1;y=x,x=fa[x])
		for (auto j:e[x]) if (j!=y)
			if (j!=be[A]&&j!=be[B]&&j!=be[C]&&j!=be[D])
				bit|=bit<<sz[j];
	if (!bit[sz[1]/2-1-sz[be[C]]])
		return puts("NO"),0;
	For(i,0,n) bit[i]=(i==0);
	for (int x=C,y=0;x;y=x,x=fa[x])
		for (auto j:e[x]) if (j!=y)
			if (j!=be[A]&&j!=be[B]&&j!=be[C]&&j!=be[D])
				bit|=bit<<sz[j];
	for (int x=D,y=0;x!=1;y=x,x=fa[x])
		for (auto j:e[x]) if (j!=y)
			if (j!=be[A]&&j!=be[B]&&j!=be[C]&&j!=be[D])
				bit|=bit<<sz[j];
	if (!bit[sz[1]/2-1-sz[be[A]]])
		return puts("NO"),0;
	puts("YES");
}