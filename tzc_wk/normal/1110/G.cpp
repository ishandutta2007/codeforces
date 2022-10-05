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
#define mt make_tuple
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
	template<typename T> void print(T x,char c){print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=5e5;
int n,hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],ec=0,deg[MAXN+5];
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
char s[MAXN+5];int dep[MAXN+5];
void clear(){for(int i=1;i<=n;i++) hd[i]=deg[i]=dep[i]=0;ec=0;}
void dfs(int x,int f){
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f) continue;
		dep[y]=dep[x]+1;dfs(y,x);
	}
}
void solve(){
	scanf("%d",&n);clear();
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);++deg[u];++deg[v];
		adde(u,v);adde(v,u);
	} scanf("%s",s+1);bool hasw=0;
	if(n<=2) return puts("Draw"),void();
	for(int i=1;i<=n;i++) if(deg[i]>=4) return puts("White"),void();
	for(int i=1;i<=n;i++) hasw|=(s[i]=='W');
	int mxd=0;for(int i=1;i<=n;i++) chkmax(mxd,deg[i]);
	for(int p=1;p<=n;p++) if(deg[p]==3){
		int cnt2=0;
		for(int e=hd[p];e;e=nxt[e]) if(deg[to[e]]>=2) cnt2++;
		if(cnt2>=2) return puts("White"),void();
	} dfs(1,0);
	if(hasw){
		for(int p=1;p<=n;p++){
			if(s[p]=='W'){
				for(int e=hd[p];e;e=nxt[e])
					if(s[to[e]]=='W') return puts("White"),void();
				if(deg[p]==3) return puts("White"),void();
				if(deg[p]==2&&n>=4) return puts("White"),void();
				if(deg[p]==1){
					for(int e=hd[p];e;e=nxt[e])
						if(deg[to[e]]==3) return puts("White"),void();
					if(mxd==3&&(~n&1)) return puts("White"),void();
				}
			} else {
				int cntw=0;
				for(int e=hd[p];e;e=nxt[e])	 cntw+=(s[to[e]]=='W');
				if(cntw>=2) return puts("White"),void();
			}
		} bool has[2]={0};
		for(int i=1;i<=n;i++) if(s[i]=='W'){
			if(has[dep[i]&1]) return puts("White"),void();
			has[dep[i]&1]=1;
		}
	} else {
		int cnt3=0;
		for(int p=1;p<=n;p++) if(deg[p]==3) ++cnt3;
		if(cnt3==2){
			int p1=0,p2=0;
			for(int p=1;p<=n;p++) if(deg[p]==3) (!p1)?(p1=p):(p2=p);
			if(~(dep[p1]^dep[p2])&1) return puts("White"),void();
		}
	} puts("Draw");
}
int main(){
	int qu;scanf("%d",&qu);
	while(qu--) solve();
	return 0;
}
/*
7
8
1 2
1 3
1 4
2 5
3 6
5 7
6 8
NNNNNNWW
7
1 2
1 3
1 4
4 5
5 6
5 7
NNNNNNN
3
1 2
2 3
WNW
5
1 2
2 3
3 4
4 5
WNNNW
9
1 2
2 3
3 4
4 5
5 6
6 7
6 8
2 9
NNNNNNNNN
8
1 2
2 3
3 4
4 5
4 6
6 7
7 8
WNNNNNNW
6
1 2
2 3
3 4
3 5
5 6
WNNWNW
*/