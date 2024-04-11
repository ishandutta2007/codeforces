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
const int MAXN=5e5;
int n,hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],ec=1;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
int siz[MAXN+5],fa[MAXN+5],bad[MAXN+5],ed[MAXN+5];
bool isbad[MAXN+5];
void dfs(int x,int f){
	fa[x]=f;siz[x]=1;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f) continue;
		dfs(y,x);siz[x]+=siz[y];ed[y]=e>>1;
	}
}
namespace have{
	ll sum[MAXN+5][2],sum_out[MAXN+5];
	int cnt[MAXN+5][2],cnt_out[MAXN+5];
	void dfs1(int x,int f){
		for(int e=hd[x];e;e=nxt[e]){
			int y=to[e];if(y==f) continue;dfs1(y,x);
			if(isbad[e>>1]){
				sum[x][1]+=sum[y][0]+cnt[y][0]+1;
				cnt[x][1]+=cnt[y][0]+1;
			} else {
				sum[x][0]+=sum[y][1];
				cnt[x][0]+=cnt[y][1];
			}
		} //printf("%d %lld %d %lld %d\n",x,sum[x][0],cnt[x][0],sum[x][1],cnt[x][1]);
	}
	void dfs2(int x,int f){
		ll tmp_sum[3]={0},tmp_cnt[3]={0};
		for(int e=hd[x];e;e=nxt[e]){
			int y=to[e];
			if(y==f){
				if(isbad[e>>1]){
					tmp_sum[1]+=sum_out[x];
					tmp_cnt[1]+=cnt_out[x];
				} else {
					tmp_sum[0]+=sum_out[x];
					tmp_cnt[0]+=cnt_out[x];
				}
			} else {
				if(isbad[e>>1]){
					tmp_sum[1]+=sum[y][0]+cnt[y][0]+1;
					tmp_cnt[1]+=cnt[y][0]+1;
				} else {
					tmp_sum[0]+=sum[y][1];
					tmp_cnt[0]+=cnt[y][1];
				}
			}
		}
		for(int e=hd[x];e;e=nxt[e]){
			int y=to[e];if(y==f) continue;
			if(isbad[e>>1]){
				tmp_sum[1]-=sum[y][0]+cnt[y][0]+1;
				tmp_cnt[1]-=cnt[y][0]+1;
				sum_out[y]=tmp_sum[0]+tmp_cnt[0]+1;
				cnt_out[y]=tmp_cnt[0]+1;
				tmp_sum[1]+=sum[y][0]+cnt[y][0]+1;
				tmp_cnt[1]+=cnt[y][0]+1;
			} else {
				tmp_sum[0]-=sum[y][1];
				tmp_cnt[0]-=cnt[y][1];
				sum_out[y]=tmp_sum[1];
				cnt_out[y]=tmp_cnt[1];
				tmp_sum[0]+=sum[y][1];
				tmp_cnt[0]+=cnt[y][1];
			} dfs2(y,x);
		} //printf("%d %lld %d\n",x,sum_out[x],cnt_out[x]);
	}
	void solve(){
		ll res=0,ss=0;
		for(int i=1;i<=n;i++) if(~siz[i]&1) res+=1ll*siz[i]*(n-siz[i]);
		dfs1(1,0);dfs2(1,0);
		for(int i=1;i<=n;i++){
			ss+=sum[i][1];
			if(siz[i]&1) ss+=sum_out[i];
		} ss>>=1;
		printf("%lld\n",ss+res);
	}
}
namespace doesnt_have{
	bool ban[MAXN+5];int cnt[MAXN+5],siz_[MAXN+5],d[MAXN+5];
	vector<int> pt;ll buc[MAXN+5],bucc[MAXN+5];
	void dfs0(int x,int f){
		siz_[x]=1;
		for(int e=hd[x];e;e=nxt[e]) if(to[e]^f){
			dfs0(to[e],x);siz_[x]+=siz_[to[e]];
		}
	}
	void dfsclc(int x,int f,int pre){
		pt.pb(x);
		for(int e=hd[x];e;e=nxt[e]){
			int y=to[e];if(y==f) continue;
			cnt[y]=cnt[x]+(pre&&(isbad[e>>1]));
			ban[y]=ban[x]|(!pre&&(!isbad[e>>1]));
			d[y]=d[x]+(siz_[y]&1);dfsclc(y,x,isbad[e>>1]);
		}
	}
	void solve(){
		int rt=0,tot=0;ll res=0;
		for(int i=1;i<=n;i++) if(bad[i]>=3) rt=i,tot++;
		dfs0(rt,0);//printf("%d\n",rt);
		for(int e=hd[rt];e;e=nxt[e]){
			int y=to[e];
			if(isbad[e>>1]){
				pt.clear();d[y]=1;cnt[y]=0;dfsclc(y,rt,1);
//				for(int z:pt) printf("%d %d %d %d\n",z,cnt[z],ban[z],d[z]);
				for(int z:pt) if((siz_[z]&1)&&!ban[z]&&bad[z]==1) res+=buc[tot-1-cnt[z]]+1ll*bucc[tot-1-cnt[z]]*d[z];
				for(int z:pt) if((siz_[z]&1)&&!ban[z]&&bad[z]==1) buc[cnt[z]]+=d[z],bucc[cnt[z]]++;
			}
		} printf("%lld\n",res);
	}
}
int main(){
	scanf("%d",&n);if(n&1) return puts("0"),0;
	for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),adde(u,v),adde(v,u);
	dfs(1,0);for(int i=2;i<=n;i++) if(siz[i]&1) bad[i]++,bad[fa[i]]++,isbad[ed[i]]=1;
	bool flg=1;
	for(int i=1;i<=n;i++){
		if(bad[i]>=5) return puts("0"),0;
		if(bad[i]>=3) flg=0;
	}
	if(flg) have::solve();
	else doesnt_have::solve();
	return 0;
}
/*
8
1 2
1 3
2 4
2 5
3 6
3 7
7 8

10
1 2
1 3
1 4
2 5
2 6
6 7
5 8
5 9
2 10

14
1 2
1 3
1 4
2 5
2 6
6 7
5 8
5 9
2 10
9 11
8 12
8 13
12 14

16
1 2
1 3
1 4
2 5
2 6
6 7
5 8
5 9
2 10
9 11
8 12
8 13
12 14
13 15
13 16

10
1 2
3 2
3 4
4 5
5 6
6 7
7 8
7 9
6 10
*/