#include"bits/stdc++.h"
#define F(i,l,r) for(register int i=l;i<=r;i++)
#define pb push_back
using namespace std;
typedef long long ll;
inline char read(){
	char ch = getchar();
	while (ch!='.' && ch!='*')
		ch = getchar();
	return ch;
}
const int N=55; 
char G[N][N],nG[N][N];bool v[N][N];
int n,m,k,c,id[N*N],sz[N*N],ans;
struct P{
	int x,y;
	P(int _=0,int __=0)
		{x=_,y=__;}
} ;
vector <P> oc,la[N*N];
queue <P> q;
const int _x[] = {-1,1,0,0}, _y[] = {0,0,-1,1};
void bfs (vector<P>&a,P fir){
	q.push(fir);
	v[fir.x][fir.y]=1;
	while (!q.empty()){
		P u=q.front();q.pop();a.pb(u);
		F(i,0,3){
			int dx = u.x+_x[i],dy = u.y+_y[i];
			if (dx>=0 && dx<=n+1 && dy>=0 && dy<=m+1 && G[dx][dy]=='.' &&!v[dx][dy])
				q.push(P(dx,dy)),v[dx][dy]=1;
		}
	}
}
bool cmp(const int&x,const int&y){return sz[x] < sz[y];}
int main(){
	scanf("%d%d%d",&n,&m,&k);F(i,1,n)F(j,1,m)G[i][j]=read();
	F(i,0,m+1)G[0][i]=G[n+1][i]='.';F(i,0,n+1)G[i][0]=G[i][m+1]='.';bfs(oc,P(0,0));
	F(i,1,n)F(j,1,m)if(!v[i][j]&&G[i][j]=='.')
		bfs(la[++c],P(i,j)),id[c]=c,sz[c]=la[c].size();
	sort(id+1,id+c+1,cmp);F(i,1,n)F(j,1,m)nG[i][j]=G[i][j];
	F(i,1,c-k)F(j,0,sz[id[i]]-1)nG[la[id[i]][j].x][la[id[i]][j].y]='*',ans++;
	printf("%d\n",ans);
	F(i,1,n)printf("%s\n",nG[i] + 1);
	return 0;
}