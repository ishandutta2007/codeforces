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
inline void debug(int x){fprintf(stderr,"ycx has aked ioi %d times\n",x);}
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
	template<typename T> void recursive_print(T x){if(!x) return;recursive_print(x/10);putc(x%10^48);}
	template<typename T> void print(T x){if(!x) putc('0');if(x<0) putc('-'),x=~x+1;recursive_print(x);}
	template<typename T> void print(T x,char c){if(!x) putc('0');if(x<0) putc('-'),x=~x+1;recursive_print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=1.25e4;
const int MAXM=1e6;
int n,m,u[MAXM+5],v[MAXM+5],val[MAXN+5],w[MAXM+5],is[MAXN+5];
vector<pii> g[MAXN+5];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;w[i]=1,i++){
		scanf("%d%d",&u[i],&v[i]);
		g[u[i]].pb(mp(v[i],i));
		g[v[i]].pb(mp(u[i],i));
		val[u[i]]++;val[v[i]]++;
	}
	for(int i=1;i<=n;i++){
		queue<pii> q;set<int> st;
		for(pii p:g[i]){
			if(p.fi>i) continue;
			if(!is[p.fi]) w[p.se]--,is[p.fi]++,val[i]--;
			q.push(p);st.insert(val[p.fi]);
		}
		while(st.find(val[i])!=st.end()){
			pii p=q.front();q.pop();
			w[p.se]++;is[p.fi]--;val[i]++;
		}
	} vector<int> resv;
	for(int i=1;i<=n;i++) if(is[i]) resv.pb(i);printf("%u\n",resv.size());
	for(int i=0;i<resv.size();i++) printf("%d%c",resv[i]," \n"[i+1==resv.size()]);
	for(int i=1;i<=m;i++) printf("%d %d %d\n",u[i],v[i],w[i]);
	return 0;
}