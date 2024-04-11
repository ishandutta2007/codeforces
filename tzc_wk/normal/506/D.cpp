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
const int SQRT=316;
int n,m,qu,u[MAXN+5],v[MAXN+5],c[MAXN+5];
int cnt[MAXN+5],blk_sz;
vector<int> cv[MAXN+5],ce[MAXN+5];
int bg_cnt=0;
map<int,int> ans[MAXN+5];
struct dsu{
	int f[MAXN+5];
	void init(){for(int i=1;i<=n;i++) f[i]=i;}
	int find(int x){return (f[x]==x)?x:f[x]=find(f[x]);}
	void merge(int x,int y){x=find(x);y=find(y);if(x!=y) f[x]=y;}
	bool query(int x,int y){return find(x)==find(y);}
} t,d[SQRT+2];
int main(){
	scanf("%d%d",&n,&m);blk_sz=(int)pow(m,0.5);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u[i],&v[i],&c[i]);
		cnt[c[i]]++;ce[c[i]].pb(i);
		cv[c[i]].pb(u[i]);cv[c[i]].pb(v[i]);
	} t.init();
	int sum=0;
	for(int i=1;i<=m;i++){
		sort(cv[i].begin(),cv[i].end());
		int siz=unique(cv[i].begin(),cv[i].end())-cv[i].begin();
		if(ce[i].size()<=blk_sz){
			for(int j=0;j<ce[i].size();j++) t.merge(u[ce[i][j]],v[ce[i][j]]);
			for(int j=0;j<siz;j++) for(int k=j+1;k<siz;k++){
				if(t.query(cv[i][j],cv[i][k]))
					ans[cv[i][j]][cv[i][k]]++;
			}
			for(int j=0;j<siz;j++) t.f[cv[i][j]]=cv[i][j];
		} else {
			bg_cnt++;d[bg_cnt].init();
			for(int j=0;j<ce[i].size();j++) d[bg_cnt].merge(u[ce[i][j]],v[ce[i][j]]);
		}
	}
	scanf("%d",&qu);
	while(qu--){
		int u,v;scanf("%d%d",&u,&v);if(u>v) swap(u,v);int res=ans[u][v];
		for(int i=1;i<=bg_cnt;i++) res+=d[i].query(u,v);
		printf("%d\n",res);
	}
	return 0;
}