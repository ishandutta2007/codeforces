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
const int MAXM=1e3;
const int MAXN=4e5;
const int AL=14;
const ll INF=1e18;
int n,m,w[MAXM+5];ll dp[(1<<AL)+5][MAXM+5];
char buf[MAXM+5],s[MAXN+5];
int ch[MAXM+5][AL+2],fail[MAXM+5],ncnt=0,ed[MAXN+5];
int qp[AL+2],qn=0;
void insert(char *s,int id){
	int len=strlen(s+1),cur=0;
	for(int i=1;i<=len;i++){
		if(!ch[cur][s[i]-'a']) ch[cur][s[i]-'a']=++ncnt;
		cur=ch[cur][s[i]-'a'];
	} ed[id]=cur;
}
void getfail(){
	queue<int> q;
	for(int i=0;i<AL;i++) if(ch[0][i]) q.push(ch[0][i]);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=0;i<AL;i++){
			if(ch[x][i]){fail[ch[x][i]]=ch[fail[x]][i];q.push(ch[x][i]);}
			else ch[x][i]=ch[fail[x]][i];
		}
	}
}
int hd[MAXM+5],nxt[MAXM+5],to[MAXM+5],ec=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
void dfs0(int x=0){for(int e=hd[x];e;e=nxt[e]) w[to[e]]+=w[x],dfs0(to[e]);}
int main(){
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		int v;scanf("%s%d",buf+1,&v);insert(buf,i);w[ed[i]]+=v;
	} getfail();for(int i=1;i<=ncnt;i++) adde(fail[i],i);dfs0();
	scanf("%s",s+1);n=strlen(s+1);
	for(int i=1;i<=n;i++) if(s[i]=='?') qp[++qn]=i;
	memset(dp,192,sizeof(dp));dp[0][0]=0;
	for(int i=0;i<qn;i++) for(int j=0;j<=ncnt;j++){
		int cur=j;ll sum=0;
		for(int k=qp[i]+1;k<qp[i+1];k++){
			cur=ch[cur][s[k]-'a'];sum+=w[cur];
		}
		for(int k=0;k<(1<<AL);k++){
			if(__builtin_popcount(k)!=i) continue;
			for(int l=0;l<AL;l++) if(!(k>>l&1)){
				chkmax(dp[k|(1<<l)][ch[cur][l]],dp[k][j]+sum+w[ch[cur][l]]);
			}
		}
	} ll ans=-INF;
	for(int i=0;i<=ncnt;i++){
		int cur=i;ll sum=0;
		for(int j=qp[qn]+1;j<=n;j++) cur=ch[cur][s[j]-'a'],sum+=w[cur];
		for(int k=0;k<(1<<AL);k++){
			if(__builtin_popcount(k)!=qn) continue;
			chkmax(ans,dp[k][i]+sum);
		}
	} printf("%lld\n",ans);
	return 0;
}