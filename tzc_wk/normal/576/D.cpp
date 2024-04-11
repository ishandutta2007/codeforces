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
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
const int MAXN=150+5;
const int MAXM=150+5;
int n,m,d[MAXN];
struct edge{
	int u,v,c;
	friend bool operator <(edge a,edge b){
		return a.c<b.c;
	}
} e[MAXM];
struct mat{
	bitset<MAXN> x[MAXN];
	friend mat operator *(mat a,mat b){
		mat c;
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
			if(a.x[i][j]) c.x[i]|=b.x[j];
		return c;
	}
} to,c; 
mat qpow(mat x,int e){
	mat ret;for(int i=1;i<=n;i++) ret.x[i][i]=1;
	while(e){if(e&1) ret=ret*x;x=x*x;e>>=1;}return ret;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].c);
	sort(e+1,e+m+1);to.x[1][1]=1;int pre=0,ans=2e9;
	for(int i=1;i<=m;i++){
		to=to*qpow(c,e[i].c-pre);pre=e[i].c;c.x[e[i].u][e[i].v]=1;
		memset(d,63,sizeof(d));
		queue<int> q;for(int j=1;j<=n;j++) if(to.x[1][j]) q.push(j),d[j]=0;
		while(!q.empty()){
			int cur=q.front();q.pop();
			for(int j=1;j<=n;j++) if(c.x[cur][j]&&d[j]>1e9){
				d[j]=d[cur]+1;q.push(j);
			}
		}
		if(d[n]<1e9) ans=min(ans,e[i].c+d[n]);
	}
	if(ans==2e9) puts("Impossible");
	else printf("%d\n",ans);
	return 0;
}