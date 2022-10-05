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
const int MAXV=1e6;
int n,qu,s,d,a[MAXN+5],f[MAXN+5],pos[MAXV+5];
set<int> cmp[MAXN+5];int cmp_cnt=0;
int find(int x){return (!f[x])?x:f[x]=find(f[x]);}
bool merge(int x,int y){
	x=find(x);y=find(y);if(x==y) return 0;
	if(cmp[x].size()<cmp[y].size()) swap(x,y);
	for(int v:cmp[y]) cmp[x].insert(v);
	cmp[y].clear();f[y]=x;cmp_cnt--;return 1;
}
set<int> st;
int hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],val[MAXN*2+5],ec=0;
void adde(int u,int v,int w){/*printf("%d %d %d\n",u,v,w);*/to[++ec]=v;val[ec]=w;nxt[ec]=hd[u];hd[u]=ec;}
int mx[MAXN+5];
void dfs(int x,int f){
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e],z=val[e];if(y==f) continue;
		mx[y]=max(mx[x],z);dfs(y,x);
	}
}
int main(){
	scanf("%d%d%d%d",&n,&qu,&s,&d);cmp_cnt=n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);st.insert(a[i]);
		pos[a[i]]=i;cmp[i].insert(i);
	}
	while(cmp_cnt>1){
		vector<pair<int,pii> > ed;
		for(int i=1;i<=n;i++) if(!cmp[i].empty()){
			for(int x:cmp[i]) st.erase(st.find(a[x]));
			for(int x:cmp[i]){
				for(int j=-1,v=-d;j<=1;j++,v=j*d) if(j!=0){
					auto it=st.lower_bound(a[x]+v);
					if(it!=st.end()) ed.pb(mp(abs(abs(a[x]-(*it))-d),mp(x,pos[*it])));
					if(it!=st.begin()){--it;ed.pb(mp(abs(abs(a[x]-(*it))-d),mp(x,pos[*it])));}
				}
			}
			for(int x:cmp[i]) st.insert(a[x]);
		} sort(ed.begin(),ed.end());
		for(int i=0;i<ed.size();i++){
			int w=ed[i].fi,x=ed[i].se.fi,y=ed[i].se.se;
			if(merge(x,y)) adde(x,y,w),adde(y,x,w);
		}
	} dfs(s,0);
	while(qu--){
		int x,k;scanf("%d%d",&x,&k);
		printf("%s\n",(mx[x]<=k)?"Yes":"No");
	}
	return 0;
}