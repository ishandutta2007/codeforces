//Created time: 2022/3/20 23:39:46
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
const int MAXN=1e5;
int n,m,qu,hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],ec=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
int rt[MAXN+5],mxd[MAXN+5],mx_out[MAXN+5],f[MAXN+5];
int dia[MAXN+5],siz[MAXN+5];
void dfs1(int x,int f,int R){
	rt[x]=R;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f) continue;dfs1(y,x,R);
		chkmax(mxd[x],mxd[y]+1);
	}
}
void dfs2(int x,int f){
	multiset<int> st;st.insert(0);
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];
		if(y==f) st.insert(mx_out[x]);
		else st.insert(mxd[y]+1);
	}
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f) continue;
		st.erase(st.find(mxd[y]+1));
		mx_out[y]=(*st.rbegin())+1;
		st.insert(mxd[y]+1);dfs2(y,x);
	}
}
vector<int> pre[MAXN+5],cc[MAXN+5];
vector<ll> suf[MAXN+5];
map<pii,ll> res;
int main(){
	scanf("%d%d%d",&n,&m,&qu);
	for(int i=1,u,v;i<=m;i++) scanf("%d%d",&u,&v),adde(u,v),adde(v,u);
	for(int i=1;i<=n;i++) if(!rt[i]) dfs1(i,0,i),dfs2(i,0);
	for(int i=1;i<=n;i++){
		f[i]=max(mxd[i],mx_out[i]);
		chkmax(dia[rt[i]],f[i]);siz[rt[i]]++;
	}
	for(int i=1;i<=n;i++) if(siz[i]){
		pre[i].resize(dia[i]+1);
		suf[i].resize(dia[i]+1);
		cc[i].resize(dia[i]+1); 
	}
	for(int i=1;i<=n;i++) cc[rt[i]][f[i]]++,pre[rt[i]][f[i]]++,suf[rt[i]][f[i]]+=f[i];
	for(int i=1;i<=n;i++) if(siz[i]){
		for(int j=1;j<=dia[i];j++) pre[i][j]+=pre[i][j-1];
		for(int j=dia[i]-1;~j;j--) suf[i][j]+=suf[i][j+1];
	}
	while(qu--){
		int x,y;scanf("%d%d",&x,&y);x=rt[x];y=rt[y];
		if(x==y){puts("-1");continue;}
		if(mp(dia[x],x)>mp(dia[y],y)) swap(x,y);
		if(res.count(mp(x,y))){printf("%.12lf\n",1.0*res[mp(x,y)]/siz[x]/siz[y]);continue;}
		ll sum=0;
		for(int i=0;i<=dia[x];i++){
			int mx=dia[y]-(i+1);
			int cnt0=(mx<0)?0:pre[y][mx];
			int cnt1=siz[y]-cnt0;ll ss=suf[y][mx+1];
			sum+=1ll*(1ll*dia[y]*cnt0+1ll*(i+1)*cnt1+ss)*cc[x][i];
		}
		res[mp(x,y)]=sum;
		printf("%.12lf\n",1.0*sum/siz[x]/siz[y]);
	}
	return 0;
}