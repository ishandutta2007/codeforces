//Created time: 2022/3/10 23:24:39
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
const int MAXN=1500;
int n,hd[MAXN*2+5],nxt[MAXN*4+5],to[MAXN*4+5],ec=0;ll ret=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
bool vis[MAXN*2+5];vector<int> chn;
void dfschn(int x){
	vis[x]=1;chn.pb(x);
	for(int e=hd[x];e;e=nxt[e]) if(!vis[to[e]]){
		dfschn(to[e]);return;
	}
}
int sgn(int x){return x>n;}
bool in(int x,int l,int r){return l<=x&&x<=r;}
int get2(int len){/*printf("get2 %d\n",len);*/return len*(len+1)/2;}
int calc1(int l,int r,int x,int y){
	if(x>y) swap(x,y);
//	printf("calc1 %d %d %d %d\n",l,r,x,y);
	if(l>r) return get2(x-1)+get2(n-y)+get2(y-x-1);
	if(in(x,l,r)||in(y,l,r)) return 0;
	if(x<l&&y<l) return (n-r+1)*(l-y);
	else if(x>r&&y>r) return l*(x-r);
	else return (l-x)*(y-r);
}
int calc2(int l,int r,int x){
//	printf("calc2 %d %d %d\n",l,r,x);
	if(l>r) return get2(x-1)+get2(n-x);
	if(in(x,l,r)) return 0;
	if(x<l) return (n-r+1)*(l-x);
	else return l*(x-r);
}
int calc3(int l,int r){return (l>r)?get2(n):(l*(n-r+1));}
int main(){
	scanf("%d",&n);
	for(int i=1,x,y;i<=n*2;i++) scanf("%d%d",&x,&y),adde(x,y),adde(y,x);
	for(int i=1;i<=n*2;i++) if(!vis[i]){
		chn.clear();dfschn(i);
//		for(int x:chn) printf("%d ",x);printf("\n");
		for(int j=0;j<chn.size();j++){
			int mxl=n,mnr=1,mxL=n,mnR=1;
			for(int k=(j+1)%chn.size(),stp=0;stp<chn.size();k=(k+1)%chn.size(),stp++){
				ll way;
				if(sgn(chn[j])==0&&sgn(chn[k])==0) way=1ll*calc1(mxl,mnr,chn[j],chn[k])*calc3(mxL,mnR);
				if(sgn(chn[j])==0&&sgn(chn[k])==1) way=1ll*calc2(mxl,mnr,chn[j])*calc2(mxL,mnR,chn[k]-n);
				if(sgn(chn[j])==1&&sgn(chn[k])==0) way=1ll*calc2(mxl,mnr,chn[k])*calc2(mxL,mnR,chn[j]-n);
				if(sgn(chn[j])==1&&sgn(chn[k])==1) way=1ll*calc1(mxL,mnR,chn[j]-n,chn[k]-n)*calc3(mxl,mnr);
				ret+=1ll*(stp>>1)*way;
//				printf("%d %d %lld [%d,%d] [%d,%d]\n",chn[j],chn[k],way,mxl,mnr,mxL,mnR);
				if(sgn(chn[k])==0) chkmin(mxl,chn[k]),chkmax(mnr,chn[k]);
				else chkmin(mxL,chn[k]-n),chkmax(mnR,chn[k]-n);
			}
		}
		int mxl=n,mnr=1,mxL=n,mnR=1;
		for(int x:chn){
			if(x<=n) chkmin(mxl,x),chkmax(mnr,x);
			else chkmin(mxL,x-n),chkmax(mnR,x-n);
		}
		ret+=1ll*calc3(mxl,mnr)*calc3(mxL,mnR)*(chn.size()>>1);
	}
	printf("%lld\n",ret);
	return 0;
}