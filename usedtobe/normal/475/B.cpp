#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#define rep(i,a,b) for (int i=a;i<=b;++i)
#define foreach(e,x) for (__typeof(x.begin())e=x.begin();e!=x.end();++e)
#define N 35
#define pb push_back
#define all(x) x.begin(),x.end()
#define mp make_pair
#define X first
#define Y second
using namespace std;
template<class T> inline void read(T&x){bool fu=0;char c;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x=-x;};
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z){read(x,y);read(z);}
typedef long long ll;
typedef pair<int,int> pii;
int n,m;
char s1[N],s2[N];bool in[N][N];
struct S{int x,y;S() {}S(int x,int y): x(x),y(y) {}};vector<S> e[N][N];S q[N*N];
bool find(int a,int b) {
	int l=0,r=1;memset(in,0,sizeof in);
	q[r]=S(a,b),in[a][b]=1;
	while(l<r)
	{
		S p=q[++l];
		foreach(i,e[p.x][p.y])
		if(!in[i->x][i->y])
		{
			in[i->x][i->y]=1;
			q[++r]=*i;
		}
	}
	return r==n*m;
}
int main() {
	read(n,m);scanf("%s %s",s1+1,s2+1);
	rep(i,1,n) rep(j,1,m) {
		if(s1[i]=='>'&&j<m) e[i][j].pb(S(i,j+1));
		if(s1[i]=='<'&&j>1) e[i][j].pb(S(i,j-1));
		if(s2[j]=='^'&&i>1) e[i][j].pb(S(i-1,j));
		if(s2[j]=='v'&&i<n) e[i][j].pb(S(i+1,j));
	}
	rep(i,1,n) rep(j,1,m) if (!find(i,j)) {return puts("NO"),0;}
	puts("YES");
	return 0;
}