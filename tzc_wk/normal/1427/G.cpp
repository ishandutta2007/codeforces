#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define ppb pop_back
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
const int MAXN=200;
const int MAXV=40000;
const int MAXE=2e5;
int n,a[MAXN+5][MAXN+5],con_S[MAXV+5],con_T[MAXV+5];
int hd[MAXV+5],to[MAXE+5],nxt[MAXE+5],f[MAXE+5],ec=1;
int getid(int x,int y){return (x-1)*n+y;}
void adde(int u,int v){/*printf("%d %d\n",u,v);*/to[++ec]=v;f[ec]=0;nxt[ec]=hd[u];hd[u]=ec;}
bool vis[MAXV+5];
int getflow(int x,int fl){
	if(fl==1&&con_T[x]) return 1;
	if(fl==-1&&con_S[x]) return 1;
	vis[x]=1;
//	printf("%d %d\n",x,fl);
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e],z=f[e];if(vis[y]) continue;
		if(fl==1&&z==1) continue;if(fl==-1&&z!=-1) continue;
		if(getflow(y,fl)) return f[e]++,f[e^1]--,1;
	} return 0;
}
int main(){
	scanf("%d",&n);vector<pair<int,pii> > col;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
		if(i+1<=n&&~a[i][j]&&~a[i+1][j]) adde(getid(i,j),getid(i+1,j)),adde(getid(i+1,j),getid(i,j));
		if(j+1<=n&&~a[i][j]&&~a[i][j+1]) adde(getid(i,j),getid(i,j+1)),adde(getid(i,j+1),getid(i,j));
		if(a[i][j]>0) col.pb(mp(a[i][j],mp(i,j))),con_T[getid(i,j)]=1;
	} sort(col.begin(),col.end());int flw=0;ll res=0;
	for(int i=0;i+1<col.size();i++){
		pii p=col[i].se;int x=getid(p.fi,p.se);
		fill0(vis);while(getflow(x,-1)) flw--,fill0(vis);
		con_T[x]=0;con_S[x]=1;fill0(vis);
		for(int j=1;j<=n*n;j++) if(con_S[j]){
			while(getflow(j,1)) flw++,fill0(vis);
		} //printf("x=%d %d\n",x,flw);
		res+=1ll*(col[i+1].fi-col[i].fi)*flw;
	} printf("%lld\n",res);
	return 0;
}