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
const int MAXN=200;
const int ALPHA=26;
int n;ll k;char buf[MAXN+5];
int ch[MAXN+5][ALPHA+2],fail[MAXN+5],ncnt=0,ed[MAXN+5];
int w[MAXN+5],a[MAXN+5];
void insert(char *s,int id){
	int len=strlen(s+1),cur=0;
	for(int i=1;i<=len;i++){
		if(!ch[cur][s[i]-'a']) ch[cur][s[i]-'a']=++ncnt;
		cur=ch[cur][s[i]-'a'];
	} ed[id]=cur;
}
void getfail(){
	queue<int> q;
	for(int i=0;i<ALPHA;i++) if(ch[0][i]) q.push(ch[0][i]);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=0;i<ALPHA;i++){
			if(ch[x][i]){fail[ch[x][i]]=ch[fail[x]][i];q.push(ch[x][i]);}
			else ch[x][i]=ch[fail[x]][i];
		}
	}
}
int hd[MAXN+5],to[MAXN+5],nxt[MAXN+5],ec=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
void dfs0(int x=0){for(int e=hd[x];e;e=nxt[e]) w[to[e]]+=w[x],dfs0(to[e]);}
struct mat{
	ll a[MAXN+5][MAXN+5];
	mat(){memset(a,192,sizeof(a));}
	mat operator *(const mat &rhs){
		mat ret;
		for(int i=1;i<=ncnt+1;i++) for(int j=1;j<=ncnt+1;j++) for(int k=1;k<=ncnt+1;k++)
			chkmax(ret.a[i][j],a[i][k]+rhs.a[k][j]);
		return ret;
	}
};
int main(){
	scanf("%d%lld",&n,&k);for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){scanf("%s",buf+1);insert(buf,i);w[ed[i]]+=a[i];}
	getfail();for(int i=1;i<=ncnt;i++) adde(fail[i],i);dfs0();
	mat trs,pw,ret;
	for(int i=0;i<=ncnt;i++) for(int j=0;j<ALPHA;j++)
		chkmax(trs.a[i+1][ch[i][j]+1],w[ch[i][j]]);
	for(int i=0;i<=ncnt;i++) pw.a[i+1][i+1]=0;
	for(;k;k>>=1,trs=trs*trs) if(k&1) pw=pw*trs;
	ret.a[1][1]=0;ret=ret*pw;ll ans=0;
//	for(int i=0;i<=ncnt;i++) printf("%d\n",ret.a[1][i+1]);
	for(int i=1;i<=ncnt+1;i++) chkmax(ans,ret.a[1][i]);
	printf("%lld\n",ans);
	return 0;
}