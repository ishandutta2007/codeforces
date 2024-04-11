#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
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
template<typename T> void read(T &x){
	x=0;char c=getchar();T neg=1;
	while(!isdigit(c)){if(c=='-') neg=-1;c=getchar();}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x*=neg;
}
const int MAXN=5e5;
const int MAXV=1<<22;
int n,hd[MAXN+5],to[MAXN+5],id[MAXN+5],nxt[MAXN+5],ec=0;
void adde(int u,int v,int w){to[++ec]=v;id[ec]=w;nxt[ec]=hd[u];hd[u]=ec;}
int msk[MAXN+5],dep[MAXN+5],siz[MAXN+5],wson[MAXN+5];
int mx[MAXV+5],ans[MAXN+5];
void dfs0(int x,int f){
	siz[x]=1;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e],z=id[e];if(y==f) continue;
		dep[y]=dep[x]+1;msk[y]=msk[x]^(1<<z);dfs0(y,x);siz[x]+=siz[y];
		if(siz[y]>siz[wson[x]]) wson[x]=y;
	}
}
int pth[MAXN+5],pth_num=0;
void getpth(int x,int f){
	pth[++pth_num]=x;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f) continue;getpth(y,x);
	}
}
void add(int x,int f){
	chkmax(mx[msk[x]],dep[x]);
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f) continue;add(y,x);
	}
}
void del(int x,int f){
	mx[msk[x]]=0;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f) continue;del(y,x);
	}
}
void dfs(int x,int f){
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f||y==wson[x]) continue;
		dfs(y,x);chkmax(ans[x],ans[y]);del(y,x);
	} if(wson[x]) dfs(wson[x],x),chkmax(ans[x],ans[wson[x]]);
	for(int i=0;i<22;i++) if(mx[msk[x]^(1<<i)])
		chkmax(ans[x],mx[msk[x]^(1<<i)]-dep[x]);
	if(mx[msk[x]]) chkmax(ans[x],mx[msk[x]]-dep[x]);
	chkmax(mx[msk[x]],dep[x]);
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f||y==wson[x]) continue;
		pth_num=0;getpth(y,x);
		for(int i=1;i<=pth_num;i++){
			for(int j=0;j<22;j++) if(mx[msk[pth[i]]^(1<<j)])
				chkmax(ans[x],mx[msk[pth[i]]^(1<<j)]+dep[pth[i]]-dep[x]*2);
			if(mx[msk[pth[i]]]) chkmax(ans[x],mx[msk[pth[i]]]+dep[pth[i]]-dep[x]*2);
		} add(y,x);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		char c;int f;cin>>f>>c;
		adde(f,i,c-'a');
	} dfs0(1,0);dfs(1,0);
	for(int i=1;i<=n;i++) printf("%d%c",ans[i],(i==n)?'\n':' ');
	return 0;
}