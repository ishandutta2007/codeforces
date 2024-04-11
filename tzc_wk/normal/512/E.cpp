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
const int MAXN=1000;
int n;
struct solver{
	vector<pii> op;int tp,a[MAXN+5][MAXN+5];
	void read(){int u,v;scanf("%d%d",&u,&v);a[u][v]=a[v][u]=1;}
	void work(){
		for(int i=1;i<=n;i++) a[i%n+1][i]=a[i][i%n+1]=1;
		for(int i=2;i<n;i++) if(a[1][i]){
			while(1){
				int ps=n;
				for(int j=i+1;j<=n;j++) if(a[1][j]){ps=j;break;}
				if(ps==i+1) break;
				for(int j=i+1;j<ps;j++) if(a[ps][j]&&a[i][j]){
					a[j][1]=a[1][j]=1;a[i][ps]=a[ps][i]=0;
					(tp)?op.pb(mp(i,ps)):op.pb(mp(1,j));break;
				}
			}
		}
	}
} s1,s2;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n-3;i++) s1.read();
	for(int i=1;i<=n-3;i++) s2.read();
	s1.tp=1;s1.work();s2.work();printf("%d\n",s1.op.size()+s2.op.size());
	for(int i=0;i<s1.op.size();i++) printf("%d %d\n",s1.op[i].fi,s1.op[i].se);
	for(int i=(int)(s2.op.size())-1;~i;i--) printf("%d %d\n",s2.op[i].fi,s2.op[i].se);
	return 0;
}