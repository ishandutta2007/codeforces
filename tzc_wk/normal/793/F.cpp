//Created time: 2022/3/13 14:07:11
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
const int BLK=200;
const int MAXN=1e5;
int n,m,qu,blk_cnt,blk_sz,L[BLK+5],R[BLK+5],bel[MAXN+5],fr[MAXN+5];
int f[MAXN+5][BLK+5],g[MAXN+5][BLK+5];
int query(int l,int r){
	if(bel[l]==bel[r]){
		int cur=l;
		for(int i=l+1;i<=r;i++) if(l<=fr[i]&&fr[i]<=cur) cur=i;
		return cur;
	} else {
		int cur=f[l][bel[r]-1];
		for(int i=L[bel[r]];i<=r;i++) if(l<=fr[i]&&fr[i]<=cur) cur=i;
		return cur;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	blk_sz=sqrt(3*n);blk_cnt=(n-1)/blk_sz+1;
	for(int i=1;i<=blk_cnt;i++){
		L[i]=(i-1)*blk_sz+1;R[i]=min(i*blk_sz,n);
		for(int j=L[i];j<=R[i];j++) bel[j]=i;
	}
	for(int i=1;i<=blk_cnt;i++) for(int j=1;j<=R[i];j++) g[j][i]=j;
	for(int i=1,l,r;i<=m;i++) scanf("%d%d",&l,&r),chkmax(g[l][bel[r]],r),fr[r]=l;
	for(int i=1;i<=n;i++) for(int j=1;j<=blk_cnt;j++) chkmax(g[i][j],g[i][j-1]);
	for(int i=1;i<=blk_cnt;i++){
		stack<int> stk;
		for(int j=R[i];j;j--){
			f[j][i]=g[j][i];
			while(!stk.empty()&&stk.top()<=g[j][i]) chkmax(f[j][i],f[stk.top()][i]),stk.pop();
			stk.push(j);
		}
	}
	scanf("%d",&qu);
	while(qu--){
		int l,r;scanf("%d%d",&l,&r);
		printf("%d\n",query(l,r));
	}
	return 0;
}