// author: xay5421
// created: Fri Apr 23 14:54:15 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
//mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
mt19937 rng(233);
int brand(){return rng()&0X7FFFFFFF;}
const int N=300005;
int n,m,rt,lc[N],rc[N],sz[N],val[N],ran[N],tg[N];
void pst(int k1,int k2){
	if(k1){
		tg[k1]+=k2;
		val[k1]+=k2;
	}
}
void psd(int k1){
	if(tg[k1]){
		pst(lc[k1],tg[k1]);
		pst(rc[k1],tg[k1]);
		tg[k1]=0;
	}
}
void upd(int k1){
	sz[k1]=sz[lc[k1]]+sz[rc[k1]]+1;
}
int _max(int x){
	while(rc[x])psd(x),x=rc[x];
	return val[x];
}
int mer(int k1,int k2){
	if(!k1||!k2)return k1+k2;
	if(ran[k1]<ran[k2]){
		psd(k1);
		rc[k1]=mer(rc[k1],k2);
		upd(k1);
		return k1;
	}else{
		psd(k2);
		lc[k2]=mer(k1,lc[k2]);
		upd(k2);
		return k2;
	}
}
void splitv(int k1,int k2,int&l,int&r){
	if(!k1){l=r=0;return;}
	psd(k1);
	if(val[k1]<=k2){
		l=k1;
		splitv(rc[k1],k2,rc[l],r);
	}else{
		r=k1;
		splitv(lc[k1],k2,l,lc[r]);
	}
	upd(k1);
}
void splits(int k1,int k2,int&l,int&r){
	if(!k1){l=r=0;return;}
	psd(k1);
	if(sz[lc[k1]]+1<=k2){
		l=k1;
		splits(rc[k1],k2-sz[lc[k1]]-1,rc[l],r);
	}else{
		r=k1;
		splits(lc[k1],k2,l,lc[r]);
	}
	upd(k1);
}
void out(int rt){
	//D("rt=%d\n",rt);
	if(!rt)return;
	out(lc[rt]);
	D("%d ",val[rt]);
	out(rc[rt]);
}
void deal(int l,int r){
	/*D("deal %d %d\n",l,r);
	if(l==5&&r==25){
		D("tree:");
		out(rt);
		D("\n");
	}*/
	int k1=0,k2=0,k3=0,k4=0;
	splitv(rt,l-1,k1,k2);
	splitv(k2,r,k2,k3);
	assert(k3);//
	splits(k3,1,k3,k4);
	pst(k2,1);
	assert(sz[k3]==1);//
	val[k3]=l;
	rt=mer(k1,mer(k3,mer(k2,k4)));
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&n);
	rep(i,1,n){
		int l,r;
		scanf("%d%d",&l,&r);
		if(rt==0||r>_max(rt)){
			++m;
			ran[m]=brand();
			val[m]=1e9;
			sz[m]=1;
			rt=mer(rt,m);
		}
		deal(l,r-1);
	}
	printf("%d\n",m);
	return 0;
}