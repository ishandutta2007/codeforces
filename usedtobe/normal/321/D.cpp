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
#define N 35
using namespace std;
template<class T> inline void read(T&x){bool fu=0;char c;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x=-x;};
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z){read(x);read(y);read(z);}
typedef long long ll;
typedef pair<int,int> pii;
//head
bool b[N][N];
int a[N][N],n,m,sum,s[2],ans;
int work(int x,int y) {
	if(b[x][y])return -a[x][y];
	else return a[x][y];
}
int main() {
	read(n);m=(n+1)/2;rep(i,1,n)rep(j,1,n)read(a[i][j]);
	re(S,1<<m) {
		sum=0;
		rep(i,1,m)b[i][m]=S>>(i-1)&1,sum+=work(i,m);
		rep(i,1,m-1)b[i+m][m]=b[m][m]^b[i][m],sum+=work(i+m,m);
		rep(j,1,m-1) {
			s[0]=s[1]=0;
			rep(st,0,1) {
				b[m][j]=st;s[st]=work(m,j);
				b[m][j+m]=b[m][m]^b[m][j];s[st]+=work(m,j+m);
				rep(i,1,m-1) {
					int res=0;
					rep(t,0,1) {
						b[i][j]=t;
						b[i][j+m]=b[i][j]^b[i][m];
						b[i+m][j]=b[m][j]^b[i][j];
						b[m+i][j+m]=b[i+m][j]^b[i+m][m];
						res=max(res,work(i,j)+work(i+m,j)+work(i,j+m)+work(i+m,j+m));
					}
					s[st]+=res;
				}
			}
			sum+=max(s[0],s[1]);
		}
		ans=max(sum,ans);
	}
	printf("%d\n",ans);
	return 0;
}