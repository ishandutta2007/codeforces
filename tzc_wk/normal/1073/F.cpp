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
const int MAXN=2e5;
int n,hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],ec=0,fa[MAXN+5],deg[MAXN+5];
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
int f[MAXN+5],fr[MAXN+5],out[MAXN+5],fr_out[MAXN+5];
pair<pii,int> dp[MAXN+5];
void dfs1(int x,int ff){
	dp[x]=mp(mp(-1,-1),x);fa[x]=ff;fr[x]=x;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==ff) continue;dfs1(y,x);
		if(f[x]) chkmax(dp[x],mp(mp(0,f[x]+f[y]+1),x));
		if(f[x]<f[y]+1) f[x]=f[y]+1,fr[x]=fr[y];
		if(~dp[y].fi.fi) chkmax(dp[x],mp(mp(dp[y].fi.fi+1,dp[y].fi.se+2),dp[y].se));
	}
}
void dfs2(int x,int ff){
	multiset<pii> st;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];
		if(y==ff) st.insert(mp(out[x]+1,fr_out[x]));
		else st.insert(mp(f[y]+1,fr[y]));
	} st.insert(mp(0,x));
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==ff) continue;
		st.erase(st.find(mp(f[y]+1,fr[y])));
		pii p=*st.rbegin();out[y]=p.fi;fr_out[y]=p.se;
		st.insert(mp(f[y]+1,fr[y]));dfs2(y,x);
	}
}
int mxl1=-1,mxl2=-1,mxu,mxv,typ,dw;
//mxu is an ancestor of mxv if typ=1
//dw is the point before mxu on the path of mxv->mxv if typ=1
multiset<int> st[MAXN+5];
pii find_dia(int x){//find the two points farthest from x
	vector<pii> vec;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==fa[x]) continue;
		vec.pb(mp(f[y],fr[y]));
	} sort(vec.begin(),vec.end(),greater<pii>());
	return mp(vec[0].se,vec[1].se);
}
int main(){
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),deg[u]++,deg[v]++,adde(u,v),adde(v,u);
	dfs1(1,0);dfs2(1,0);
	for(int i=1;i<=n;i++) for(int e=hd[i];e;e=nxt[e]){
		int j=to[e];
		if(j!=fa[i]) st[i].insert(f[j]+1);
		else st[i].insert(out[i]+1);
	}
	for(int i=2;i<=n;i++) if(~dp[i].fi.fi&&deg[fa[i]]>=3){//type 1
		st[fa[i]].erase(st[fa[i]].find(f[i]+1));
		int len=dp[i].fi.se+(*st[fa[i]].rbegin())+(*++st[fa[i]].rbegin());
		if(mp(dp[i].fi.fi+1,len+2)>mp(mxl1,mxl2)){
			mxl1=dp[i].fi.fi+1;mxl2=len+2;
			mxu=fa[i];mxv=dp[i].se;typ=1;dw=i;
		}
	}
	for(int i=1;i<=n;i++){
		vector<pair<pii,int> > vec;
		for(int e=hd[i];e;e=nxt[e]){
			int y=to[e];if(y==fa[i]) continue;
			if(~dp[y].fi.fi) vec.pb(dp[y]);
		} sort(vec.begin(),vec.end(),greater<pair<pii,int> >());
		if(vec.size()>=2){
			int len1=vec[0].fi.fi+vec[1].fi.fi+2;
			int len2=vec[0].fi.se+vec[1].fi.se+4;
			if(mp(len1,len2)>mp(mxl1,mxl2)){
				mxl1=len1;mxl2=len2;
				mxu=vec[0].se;mxv=vec[1].se;
				typ=2;
			}
		}
	} //printf("%d %d %d\n",mxu,mxv,typ);
	int res1=0,res2=0,res3=0,res4=0;
	if(typ==1){
		pii tmp=find_dia(mxv);
		res1=tmp.fi;res2=tmp.se;
		vector<pii> vec;
		for(int e=hd[mxu];e;e=nxt[e]){
			int y=to[e];
			if(y==dw) continue;
			if(y!=fa[mxu]) vec.pb(mp(f[y],fr[y]));
			else vec.pb(mp(out[mxu],fr_out[mxu]));
		} sort(vec.begin(),vec.end());
		res3=vec[0].se;res4=vec[1].se;
	} else {
		pii p1=find_dia(mxu),p2=find_dia(mxv);
		res1=p1.fi;res2=p1.se;res3=p2.fi;res4=p2.se;
	} printf("%d %d\n%d %d\n",res1,res3,res2,res4);
	return 0;
}