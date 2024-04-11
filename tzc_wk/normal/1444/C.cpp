#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
namespace fastio{
	#define FILE_SIZE 1<<23
	char rbuf[FILE_SIZE],*p1=rbuf,*p2=rbuf,wbuf[FILE_SIZE],*p3=wbuf;
	inline char getc(){return p1==p2&&(p2=(p1=rbuf)+fread(rbuf,1,FILE_SIZE,stdin),p1==p2)?-1:*p1++;}
	inline void putc(char x){(*p3++=x);}
	template<typename T> void read(T &x){
		x=0;char c=getchar();T neg=0;
		while(!isdigit(c)) neg|=!(c^'-'),c=getchar();
		while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
		if(neg) x=(~x)+1;
	}
	template<typename T> void recursive_print(T x){return (!x)?void():(recursive_print(x/10),putc(x%10^48),void());}
	template<typename T> void print(T x){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);}
	template<typename T> void print(T x,char c){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=5e5;
int n,m,k,a[MAXN+5],u[MAXN+5],v[MAXN+5],col[MAXN+5];
vector<int> sm[MAXN+5];
int ban[MAXN+5],f[MAXN*2+5];
int find(int x){return (!f[x])?x:f[x]=find(f[x]);}
bool merge(int x,int y){/*printf("merge %d %d\n",x,y);*/x=find(x);y=find(y);return (x==y)?0:(f[x]=y,1);}
vector<int> ps[MAXN+5];
int id[MAXN+5],_a[MAXN+5],nn=0,ne=0;
int _u[MAXN+5],_v[MAXN+5],pn=0,_c[MAXN+5];
map<pii,int> prs;
vector<int> dif[MAXN+5];
bool check(int x){return find(x)!=find(x+n);}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),ps[a[i]].pb(i);
	for(int i=1;i<=m;i++) scanf("%d%d",&u[i],&v[i]);
	for(int i=1;i<=m;i++) if(a[u[i]]==a[v[i]]) sm[a[u[i]]].pb(i);
	for(int i=1;i<=k;i++){
		for(int e:sm[i]) merge(u[e]+n,v[e]),merge(u[e],v[e]+n);
		for(int e:sm[i]) ban[i]|=!check(u[e]),ban[i]|=!check(v[e]);
		if(!ban[i]){
			for(int x:ps[i]){
				int t=(find(x)-1)%n+1;
				if(find(x)==find(t)) col[x]=0;
				else col[x]=1;
			}
			for(int e:sm[i]) f[u[e]]=f[v[e]]=f[u[e]+n]=f[v[e]+n]=0;
			for(int e:sm[i]) merge(u[e],v[e]);
			for(int x:ps[i]){
				if(!id[find(x)]) id[find(x)]=++nn,_a[nn]=i;
				id[x]=id[find(x)];
			} for(int x:ps[i]) f[x]=0;
		} else {
			for(int e:sm[i]) f[u[e]]=f[v[e]]=f[u[e]+n]=f[v[e]+n]=0;
		}
	}
	for(int i=1;i<=m;i++){
		if(a[u[i]]==a[v[i]]) continue;
		if(ban[a[u[i]]]||ban[a[v[i]]]) continue;
		_u[++ne]=id[u[i]];_v[ne]=id[v[i]];_c[ne]=(col[u[i]]==col[v[i]]); 
		int bu=_a[_u[ne]],bv=_a[_v[ne]];
		if(bu>bv) swap(bu,bv);
		if(!prs[mp(bu,bv)]) prs[mp(bu,bv)]=++pn;
		dif[prs[mp(bu,bv)]].pb(ne);
	}
//	for(int i=1;i<=ne;i++) printf("%d %d\n",_u[i],_v[i]);
	int lft=k;for(int i=1;i<=k;i++) lft-=ban[i];
	ll res=1ll*lft*(lft-1)/2;
	for(pair<pii,int> p:prs){
		int x=p.se,ok=1;
		for(int e:dif[x]){
			if(_c[e]) merge(_u[e],_v[e]+n),merge(_u[e]+n,_v[e]);
			else merge(_u[e],_v[e]),merge(_u[e]+n,_v[e]+n);
		}
		for(int e:dif[x]) ok&=check(_u[e]),ok&=check(_v[e]);
		res-=(!ok);
//		printf("%d %d %d\n",p.fi.fi,p.fi.se,ok);
		for(int e:dif[x]) f[_u[e]]=f[_v[e]]=f[_u[e]+n]=f[_v[e]+n]=0;
	} printf("%lld\n",res);
	return 0;
}