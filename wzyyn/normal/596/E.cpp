#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=205,M=40005;
int n,m,Q,nd,co,dx[15],dy[15];
int id[N][N],a[M],to[M],vis[M];
vector<int> e[M],vec[M];
char s[N][N],ss[1000005];
int q[M],bel[M],ava[M][15];
void solve(){
	scanf("%s",ss+1);
	int len=strlen(ss+1),h=0,t=0;
	For(i,1,nd) bel[i]=-1;
	For(i,1,co){
		int pos=len;
		for (;pos&&ava[i][ss[pos]-'0'];--pos);
		//cout<<pos<<endl;
		if (!pos) return puts("YES"),void(0);
		for (auto j:vec[i]) bel[j]=pos,q[++t]=j;
	}
	while (h!=t){
		int x=q[++h];
		//cout<<x<<' '<<bel[x]<<endl;
		for (auto i:e[x])
			if (bel[i]==-1){
				int nv=bel[x]-((ss[bel[x]]-'0')==a[i]);
				if (!nv) return puts("YES"),void(0);
				bel[i]=nv; q[++t]=i;
			}
	}
	puts("NO");
}
int main(){
	//freopen("1.in","r",stdin);
	scanf("%d%d%d",&n,&m,&Q);
	For(i,1,n) scanf("%s",s[i]+1);
	For(i,0,9) scanf("%d%d",&dx[i],&dy[i]);
	For(i,1,n) For(j,1,m)
		id[i][j]=++nd,a[nd]=s[i][j]-'0';
	For(i,1,n) For(j,1,m){
		int c=s[i][j]-'0';
		int nx=i+dx[c],ny=j+dy[c];
		if (nx<1||ny<1||nx>n||ny>m) nx=i,ny=j;
		to[id[i][j]]=id[nx][ny];
		//cout<<id[i][j]<<' '<<id[nx][ny]<<endl;
	}
	For(i,1,nd) e[to[i]].PB(i);
	For(i,1,nd) if (!vis[i]){
		int x=i; ++*vis;
		for (;!vis[x];x=to[x]) vis[x]=*vis;
		if (vis[x]!=*vis) continue;
		//cout<<i<<' '<<x<<endl;
		++co;
		for (int y=x;;){
			//cout<<co<<' '<<y<<endl;
			ava[co][a[y]]=1;
			vec[co].PB(y);
			if (to[y]==x) break;
			y=to[y];
		}
	}
	while (Q--) solve();
}