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
const int MAXN=1e5;
const int MAXLEN=1e6;
const int ALPHA=26;
int n,qu,id[MAXN+5];char buf[MAXLEN+5];bitset<MAXN+5> vis;
int ch[MAXLEN+5][ALPHA+2],ncnt=0,fail[MAXLEN+5];
int insert(string s){
	int cur=0;
	for(int i=0;i<s.size();i++){
		if(!ch[cur][s[i]-'a']) ch[cur][s[i]-'a']=++ncnt;
		cur=ch[cur][s[i]-'a'];
	} return cur;
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
int hd[MAXLEN+5],nxt[MAXLEN+5],to[MAXLEN+5],ec=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
int bgt[MAXLEN+5],edt[MAXLEN+5],tim=0;
void dfs(int x){bgt[x]=++tim;for(int e=hd[x];e;e=nxt[e]) dfs(to[e]);edt[x]=tim;}
ll t[MAXLEN+5];
void add(int x,int v){for(int i=x;i<=ncnt+1;i+=(i&(-i))) t[i]+=v;}
ll query(int x){int ret=0;for(int i=x;i;i&=(i-1)) ret+=t[i];return ret;}
int main(){
	scanf("%d%d",&qu,&n);
	for(int i=1;i<=n;i++){string s;cin>>s;id[i]=insert(s);vis[i]=1;}
	getfail();for(int i=1;i<=ncnt;i++) adde(fail[i],i);dfs(0);
	for(int i=1;i<=n;i++) add(bgt[id[i]],1),add(edt[id[i]]+1,-1);
	for(int i=1;i<=qu;i++){
		scanf("%s",buf+1);int len=strlen(buf+1);string ss;
		for(int j=2;j<=len;j++) ss+=buf[j];
		if(buf[1]=='?'){
			int cur=0;ll sum=0;
			for(int j=0;j<ss.size();j++) cur=ch[cur][ss[j]-'a'],sum+=query(bgt[cur]);
			printf("%lld\n",sum);
		} else {
			int x;sscanf(buf+2,"%d",&x);
			if(buf[1]=='+'){if(!vis[x]) add(bgt[id[x]],1),add(edt[id[x]]+1,-1),vis[x]=1;}
			else{if(vis[x]) add(bgt[id[x]],-1),add(edt[id[x]]+1,1),vis[x]=0;}
		}
	}
	return 0;
}
/*
6 3
bbaaa
abaaab
aa
-2
-2
+1
?abaabaaab
*/