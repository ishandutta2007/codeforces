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
const int MAXN=1.5e5;
const int MAXV=1e6;
int n,qu,a[MAXN+5];
int mnp[MAXV+5],pr[MAXV/10+5],prcnt=0,vis[MAXV+5];
vector<int> pf[MAXV+5];
void sieve(int n){
	for(int i=2;i<=n;i++){
		if(!vis[i]){pr[++prcnt]=i;mnp[i]=i;}
		for(int j=1;j<=prcnt&&pr[j]*i<=n;j++){
			vis[pr[j]*i]=1;mnp[pr[j]*i]=pr[j];
			if(i%pr[j]==0) break;
		}
	}
	for(int i=2;i<=n;i++){
		int cur=i;
		while(cur^1){
			int p=mnp[cur];pf[i].pb(p);
			while(cur%p==0) cur/=p;
		}
	}
}
int f[MAXV+5],id[MAXV+5],cmp=0;
int find(int x){return (!f[x])?x:f[x]=find(f[x]);}
void merge(int x,int y){x=find(x);y=find(y);(x^y)&&(f[x]=y);}
set<int> st[MAXV+5];
int main(){
	scanf("%d%d",&n,&qu);sieve(MAXV+1);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<pf[a[i]].size();j++)
			merge(pf[a[i]][0],pf[a[i]][j]);
	for(int i=1;i<=prcnt;i++) if(find(pr[i])==pr[i]) id[pr[i]]=++cmp;
	for(int i=1;i<=n;i++){
		int bel=id[find(pf[a[i]][0])];
		for(int j=0;j<pf[a[i]+1].size();j++)
			st[bel].insert(id[find(pf[a[i]+1][j])]);
		for(int j=0;j<pf[a[i]+1].size();j++)
			for(int k=0;k<j;k++){
				st[id[find(pf[a[i]+1][j])]].insert(id[find(pf[a[i]+1][k])]);
				st[id[find(pf[a[i]+1][k])]].insert(id[find(pf[a[i]+1][j])]);
			}
	}
	while(qu--){
		int x,y;scanf("%d%d",&x,&y);
		int fx=id[find(pf[a[x]][0])],fy=id[find(pf[a[y]][0])];
//		printf("%d %d\n",fx,fy);
		if(fx==fy) puts("0");
		else if((~a[x]&1)||(~a[y]&1)) puts("1");
		else if(st[fx].find(fy)!=st[fx].end()||st[fy].find(fx)!=st[fy].end())
			puts("1");
		else puts("2");
	}
	return 0;
}