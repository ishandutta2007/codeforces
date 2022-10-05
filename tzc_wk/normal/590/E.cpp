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
const int MAXN=750;
const int MAXLEN=1e7;
const int MAXV=1502;
const int MAXE=1.5e6;
const int INF=0x3f3f3f3f;
int n;string s[MAXN+5];
int ch[MAXLEN+5][2],fail[MAXLEN+5],pos[MAXLEN+5],ncnt=0;
bool d[MAXN+5][MAXN+5];
void insert(string s,int id){
	int cur=0;
	for(int i=0;i<s.size();i++){
		if(!ch[cur][s[i]-'a']) ch[cur][s[i]-'a']=++ncnt;
		cur=ch[cur][s[i]-'a'];
	} pos[cur]=id;
}
void getfail(){
	queue<int> q;
	for(int i=0;i<2;i++) if(ch[0][i]) q.push(ch[0][i]);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=0;i<2;i++){
			if(ch[x][i]){
				fail[ch[x][i]]=ch[fail[x]][i];q.push(ch[x][i]);
				if(!pos[ch[x][i]]) pos[ch[x][i]]=pos[fail[ch[x][i]]]; 
			} else ch[x][i]=ch[fail[x]][i];
		}
	}
}
int S=1501,T=1502;
int hd[MAXV+5],to[MAXE+5],cap[MAXE+5],nxt[MAXE+5],ec=1; 
void adde(int u,int v,int f){
	to[++ec]=v;cap[ec]=f;nxt[ec]=hd[u];hd[u]=ec;
	to[++ec]=u;cap[ec]=0;nxt[ec]=hd[v];hd[v]=ec;
}
int dep[MAXV+5],now[MAXV+5];
bool getdep(){
	memset(dep,-1,sizeof(dep));dep[S]=0;
	queue<int> q;q.push(S);now[S]=hd[S];
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int e=hd[x];e;e=nxt[e]){
			int y=to[e],z=cap[e];
			if(!~dep[y]&&z){dep[y]=dep[x]+1;now[y]=hd[y];q.push(y);}
		}
	} return ~dep[T];
}
int getflow(int x,int f){
	if(x==T) return f;int ret=0;
	for(int &e=now[x];e;e=nxt[e]){
		int y=to[e],z=cap[e];
		if(z&&dep[y]==dep[x]+1){
			int w=getflow(y,min(f-ret,z));
			ret+=w;cap[e]-=w;cap[e^1]+=w;
			if(f==ret) return ret;
		}
	} return ret;
}
int dinic(){
	int ret=0;
	while(getdep()) ret+=getflow(S,INF);
	return ret;
}
bool vis[MAXV+5];
void dfs(int x){
	if(vis[x]) return;vis[x]=1;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e],z=cap[e];
		if(z) dfs(y);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) cin>>s[i],insert(s[i],i);
	getfail();
//	for(int i=1;i<=ncnt;i++) printf("%d\n",pos[i]);
	for(int i=1;i<=n;i++){
		int cur=0;
		for(int j=0;j<s[i].size();j++){
			if(pos[cur]) d[i][pos[cur]]=1;
			cur=ch[cur][s[i][j]-'a'];
		} if(pos[fail[cur]]) d[i][pos[fail[cur]]]=1;
	}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
		d[i][j]|=d[i][k]&d[k][j];
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
		if(d[i][j]&&i!=j) adde(i,j+n,1);
	}
	for(int i=1;i<=n;i++) adde(S,i,1),adde(i+n,T,1);
	printf("%d\n",n-dinic());dfs(S);vector<int> ans;
	for(int i=1;i<=n;i++) if(vis[i]&&!vis[i+n]) ans.pb(i);
	sort(ans.begin(),ans.end());ffe(it,ans) printf("%d ",*it);
	return 0;
}