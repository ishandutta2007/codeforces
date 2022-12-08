#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<cstdio>
#include<cmath>
#include<stack>
#include<queue>
#include<set>
#include<map>
#define Re(i,x) for (i=x.begin();i!=x.end();++i)
#define For(i,u) for (int i=H[u];i;i=nxt[i])
#define re(i,a) for (int i=0;i<(int)a;++i)
#define rep(i,a,b) for (int i=a;i<=b;++i)
#define dep(i,a,b) for (int i=a;i>=b;--i)
#define POSIN(x,y) (x>=1&&x<=n&&y>=1&&y<=m)
#define clr(x) memset(x,0,sizeof x)
#define SZ(x) ((int)x.size())
#define TWO(x) (1<<(x))
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define INF 0x7fffffff
#define N 4005
using namespace std;
template<class T> inline void read(T&x){bool fu=0;char c;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x=-x;};
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z){read(x);read(y);read(z);}
typedef long long ll;
typedef pair<int,int> pii;
//head
int n,m,a[N][N],pre[N],w[N][N],f[N][N],s[N][N];
int main() {
	read(n,m);rep(i,1,n)rep(j,1,n)read(a[i][j]),a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
	rep(i,1,n)rep(j,i,n)w[i][j]=(a[j][j]-a[i-1][j]-a[j][i-1]+a[i-1][i-1])/2;
	rep(i,1,n)f[0][i]=1e9;
	rep(i,1,m)
		dep(j,n,1){
			f[i][j]=1e9;
			for(int k=s[i-1][j];k<=(j==n?n:s[i][j+1])&&k<j;k++){
				int tmp=f[i-1][k]+w[k+1][j];
				if(f[i][j]>tmp)f[i][j]=tmp,s[i][j]=k;
			}
		}
	printf("%d\n",f[m][n]);
	return 0;
}