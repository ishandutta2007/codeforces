#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,src,sink,ncnt,tot;
const int dir[4][2]={0,1,1,0,0,-1,-1,0};
int lab[205][205],level[40005],q[40005],v[500005],rev[500005],nxt[500005],c[500005],h[40005];
char s[205][205];

void addedge(int x,int y,int z1,int z2){
	v[++tot]=y; c[tot]=z1; rev[tot]=tot+1; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; c[tot]=z2; rev[tot]=tot-1; nxt[tot]=h[y]; h[y]=tot;
}

bool bfs(){
	memset(level,-1,sizeof(level));
	int front=0,rear=0;
	level[src]=0,q[rear++]=src;
	while(front<rear){
		int t=q[front++];
		for(int p=h[t];p;p=nxt[p]){
			if(c[p]&&level[v[p]]<0){
				level[v[p]]=level[t]+1;
				q[rear++]=v[p];
			}
		}
		if(level[sink]>=0) return true;
	}
	return false;
}

int dfs(int u,int low){
	if(u==sink) return low;
	int res=0;
	for(int p=h[u];p;p=nxt[p]){
		if(c[p]&&level[v[p]]==level[u]+1){
			int flow=dfs(v[p],min(low,c[p]));
			res+=flow,low-=flow,c[p]-=flow,c[rev[p]]+=flow;
		}
	}
	if(res==0) level[u]=-1;
	return res;
}

int dinic(){
	int ret=0;
	while(bfs()) ret+=dfs(src,1<<30);
	return ret;
}

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]=='.') continue;
			lab[i][j]=++ncnt;
		}
	}
	src=0,sink=ncnt+1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]=='.') continue;
			int tmp[2]={0,0};
			for(int k=0;k<4;k++){
				int dx=i+dir[k][0],dy=j+dir[k][1];
				if(dx<1||dx>n||dy<1||dy>m||s[dx][dy]=='.') tmp[k&1]++;
				if(dx>=1&&dx<=n&&dy>=1&&dy<=m&&s[dx][dy]=='#'&&k<2) addedge(lab[i][j],lab[dx][dy],1,1);
			}
			if(tmp[0]) addedge(src,lab[i][j],tmp[0],0);
			if(tmp[1]) addedge(lab[i][j],sink,tmp[1],0);
		}
	}
	printf("%d\n",dinic()/2);
	return 0;
}