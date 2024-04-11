//#pragma comment(linker,"/stack:200000000")
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
const int MOD=998244353;
const int MAXN=1e5;
int n,hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],ec=0,deg[MAXN+5],pw2[MAXN+5];
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
int res[MAXN+5],vis[MAXN+5],cdeg[MAXN+5],lft[MAXN+5];
void solve(){
	scanf("%d",&n);ec=0;for(int i=1;i<=n;i++) hd[i]=deg[i]=res[i]=0;int cnt=0;
	for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),deg[u]++,deg[v]++,adde(u,v),adde(v,u);
	for(int i=2;i<=n-1;i++){
		if((n-1)%i) continue;queue<int> q;bool flg=1;
		for(int j=1;j<=n;j++) vis[j]=0,cdeg[j]=lft[j]=deg[j];
		for(int j=1;j<=n;j++) if(deg[j]==1) q.push(j);
		while(!q.empty()){
			int x=q.front();q.pop();vis[x]=1;int y=0;
			for(int e=hd[x];e;e=nxt[e]) if(!vis[to[e]]) y=to[e];
			if(!y){
				if(cdeg[x]%i){flg=0;break;}
			} else {
				if(cdeg[x]%i==0) cdeg[y]--;
				else if(cdeg[x]%i==1) cdeg[x]--;
				else{flg=0;break;}
				if((--lft[y])<=1) q.push(y);
			}
		} res[i]=flg;cnt+=flg;
	} res[1]=pw2[n-1];
	for(int i=n;i;i--) for(int j=i<<1;j<=n;j+=i) res[i]=(res[i]-res[j]+MOD)%MOD;
	for(int i=1;i<=n;i++) printf("%d%c",res[i]," \n"[i==n]);
}
int main(){
	for(int i=(pw2[0]=1);i<=MAXN;i++) pw2[i]=(pw2[i-1]<<1)%MOD;
	int qu;scanf("%d",&qu);while(qu--) solve();
	return 0;
}
/*
1
7
1 2
1 3
1 4
1 5
2 6
2 7
*/