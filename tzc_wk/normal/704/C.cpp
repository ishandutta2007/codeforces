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
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
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
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=1e5;
const int MOD=1e9+7;
void add(int &x,int y){x+=y;if(x>=MOD) x-=MOD;}
int n,m,msk[MAXN+5],deg[MAXN+5];bool vis[MAXN+5];
int sgn(int x){return (x>0)?0:1;}
struct edge{
	int u,v,su,sv,id;
	edge(int _u,int _v,int _su,int _sv,int _id):u(_u),v(_v),su(_su),sv(_sv),id(_id){}
};
vector<edge> g[MAXN+5];
int f[MAXN+5][2];
vector<pair<int,pii> > ch;
void dfs(int x,int pre,int rt){
	vis[x]=1;
	for(int i=0;i<g[x].size();i++){
		int y=g[x][i].v,sx=g[x][i].su,sy=g[x][i].sv,id=g[x][i].id;
		if(id==pre) continue;ch.pb(mp(y,mp(sx,sy)));
		if(y^rt){dfs(y,id,rt);return;}
	}
}
int main(){
	scanf("%d%d",&m,&n);int goal=1;
	memset(msk,-1,sizeof(msk));int mul=1;
	f[0][0]=1;int grp_n=0;
	for(int i=1;i<=m;i++){
		int k;scanf("%d",&k);
		if(k==1){
			int x;scanf("%d",&x);
			if(!~msk[abs(x)]) msk[abs(x)]=sgn(x);
			else{
				if(msk[abs(x)]^sgn(x)) goal^=1;
				msk[abs(x)]=-1;
			}
		} else {
			int u,v;scanf("%d%d",&u,&v);
			if(u==v){
				vis[abs(u)]=1;grp_n++;
				f[grp_n][0]=f[grp_n][1]=(f[grp_n-1][0]+f[grp_n-1][1])%MOD;
			} else if(u+v==0) goal^=1,vis[abs(u)]=1,mul=2ll*mul%MOD;
			else if(u+v!=0){
				g[abs(u)].pb(edge(abs(u),abs(v),sgn(u),sgn(v),i));
				g[abs(v)].pb(edge(abs(v),abs(u),sgn(v),sgn(u),i));
				deg[abs(u)]++;deg[abs(v)]++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(!deg[i]){
			if(!~msk[i]&&!vis[i]) mul=2ll*mul%MOD;
			else if(!vis[i]){
				grp_n++;
				f[grp_n][0]=f[grp_n][1]=(f[grp_n-1][0]+f[grp_n-1][1])%MOD;
			}
		} else if(deg[i]==1&&!vis[i]){
			ch.clear();ch.pb(mp(i,mp(0,0)));dfs(i,0,0);vector<int> dp[2][2];
			for(int j=0;j<2;j++) for(int k=0;k<2;k++) dp[j][k].resize(ch.size());
			if(~msk[i]) for(int j=0;j<2;j++) dp[j][j^msk[i]][0]=1;
			else for(int j=0;j<2;j++) dp[j][0][0]=1;
			for(int j=1;j<ch.size();j++){
				int su=ch[j].se.fi,sv=ch[j].se.se;
				for(int o=0;o<2;o++) for(int p=0;p<2;p++) for(int q=0;q<2;q++){
					add(dp[o][((p^su)|(o^sv))^q][j],dp[p][q][j-1]);
				}
			} grp_n++;int lst=ch.back().fi;
			for(int o=0;o<2;o++) for(int p=0;p<2;p++){
				int res=o;if(~msk[lst]) res^=(p^msk[lst]);
				add(f[grp_n][0],1ll*f[grp_n-1][res]*dp[p][o].back()%MOD);
				add(f[grp_n][1],1ll*f[grp_n-1][res^1]*dp[p][o].back()%MOD);
			}
//			printf("Group %d:\n",grp_n);
//			for(int j=0;j<ch.size();j++) printf("%d %d %d\n",ch[j].fi,ch[j].se.fi,ch[j].se.se);
//			for(int j=0;j<ch.size();j++) printf("%d %d %d %d\n",dp[0][0][j],dp[0][1][j],dp[1][0][j],dp[1][1][j]);
//			printf("%d %d %d\n",i,f[grp_n][0],f[grp_n][1]);
		}
	}
	for(int i=1;i<=n;i++) if(deg[i]==2&&!vis[i]){
		ch.clear();ch.pb(mp(i,mp(0,0)));dfs(i,0,i);vector<int> dp[2][2][2];
		for(int j=0;j<2;j++) for(int k=0;k<2;k++) for(int l=0;l<2;l++) dp[j][k][l].resize(ch.size());
		for(int j=0;j<2;j++) dp[j][0][j][0]=1;
		for(int j=1;j<ch.size();j++){
			int su=ch[j].se.fi,sv=ch[j].se.se;
			for(int o=0;o<2;o++) for(int p=0;p<2;p++)
				for(int q=0;q<2;q++) for(int r=0;r<2;r++){
					add(dp[o][((p^su)|(o^sv))^q][r][j],dp[p][q][r][j-1]);
				}
		} grp_n++;int lst=ch.back().fi;
		for(int o=0;o<2;o++) for(int p=0;p<2;p++){
			add(f[grp_n][0],1ll*f[grp_n-1][o]*dp[p][o][p].back()%MOD);
			add(f[grp_n][1],1ll*f[grp_n-1][o^1]*dp[p][o][p].back()%MOD);
		}
//		printf("Group %d:\n",grp_n);
//		for(int j=0;j<ch.size();j++) printf("%d %d %d\n",ch[j].fi,ch[j].se.fi,ch[j].se.se);
//		printf("%d %d %d\n",i,f[grp_n][0],f[grp_n][1]);
	}
	printf("%d\n",1ll*f[grp_n][goal]*mul%MOD);
	return 0;
}
/*
8 10
1 -5
2 4 -6
2 -2 -6
2 -7 9
2 10 -1
2 3 -1
2 -8 9
2 5 8
*/