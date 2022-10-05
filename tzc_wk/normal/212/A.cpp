//Created time: 2022/3/10 16:26:41
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/hash_policy.hpp>
//#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
//using namespace __gnu_pbds;
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
#ifdef FASTIO
#define FILE_SIZE 1<<23
char rbuf[FILE_SIZE],*p1=rbuf,*p2=rbuf,wbuf[FILE_SIZE],*p3=wbuf;
inline char getc(){return p1==p2&&(p2=(p1=rbuf)+fread(rbuf,1,FILE_SIZE,stdin),p1==p2)?-1:*p1++;}
inline void putc(char x){(*p3++=x);}
template<typename T> void read(T &x){
	x=0;char c=getc();T neg=0;
	while(!isdigit(c)) neg|=(c=='-'),c=getc();
	while(isdigit(c)) x=(x<<3)+(x<<1)+(c-'0'),c=getc();
	if(neg) x=-x;
}
template<typename T> void recursive_print(T x){if(!x) return;recursive_print(x/10);putc(x%10^48);}
template<typename T> void print(T x){if(!x) putc('0');if(x<0) putc('-'),x=-x;recursive_print(x);}
template<typename T> void print(T x,char c){print(x);putc(c);}
void readstr(char *s){
	char c=getc();
	while(c<=32||c>=127) c=getc();
	while(c>32&&c<127) s[0]=c,s++,c=getc();
	(*s)=0;
}
void printstr(string s){for(int i=0;i<s.size();i++) putc(s[i]);}
void printstr(char *s){int len=strlen(s);for(int i=0;i<len;i++) putc(s[i]);}
void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
#endif
const int MAXN=400;
const int MAXM=5e3;
const int MAXT=200;
int n,m,k,t,u[MAXM+5],v[MAXM+5],id[MAXN+5],deg[MAXN+5],idcnt;
int occ[MAXM*2+5][MAXT+5],res[MAXM+5];
int get(int x){for(int i=1;i<=t;i++) if(!occ[x][i]) return i;}
void flip(int p,int x,int y){
	int e=occ[p][x],q=u[e]^v[e]^p;
	occ[p][x]=occ[q][x]=0;
	if(occ[q][y]) flip(q,y,x);
	occ[p][y]=occ[q][y]=e;res[e]=y;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&k,&t);
	for(int i=1;i<=k;i++){
		scanf("%d%d",&u[i],&v[i]);v[i]+=n;
		if(deg[u[i]]%t==0) id[u[i]]=++idcnt;
		if(deg[v[i]]%t==0) id[v[i]]=++idcnt;
		deg[u[i]]++;deg[v[i]]++;u[i]=id[u[i]];v[i]=id[v[i]];
		int A=get(u[i]),B=get(v[i]);
		if(A==B) occ[u[i]][A]=occ[v[i]][B]=i,res[i]=A;
		else{
			if(occ[u[i]][B]) flip(u[i],B,A);
			occ[u[i]][B]=occ[v[i]][B]=i,res[i]=B;
		}
	}
	int sum=0;
	for(int i=1;i<=n+m;i++) sum+=(deg[i]%t!=0);
	printf("%d\n",sum);
	for(int i=1;i<=k;i++) printf("%d%c",res[i]," \n"[i==k]);
	return 0;
}