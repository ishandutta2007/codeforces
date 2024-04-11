#include<iostream>
#include<cstdio>
#define rep(i,a,n) for(int _tmp=n,i=a;i<=_tmp;++i)
#define dep(i,a,n) for(int _tmp=n,i=a;i>=_tmp;--i)
#define re(i,a,n) for(int _tmp=n,i=a;i<_tmp;++i)
#define fec(i,a) for(__typeof a.begin() i=a.begin();i!=a.end();++i)
#define For(i,v,u) for(int i=H[u],v=to[i];i;i=nxt[i],v=to[i])
#define si(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inf 1e18
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
template<class T> inline void read(T&x){char c;bool fu=0;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x*=-1;}
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z) {read(x,y);read(z);}
template<class T> inline void MAX(T&x,T y){if(x<y)x=y;}
template<class T> inline void MIN(T&x,T y){if(x>y)x=y;}
typedef long long ll;
typedef pair<int,int> pii;
const int N=111;
//head
int n,L;
char s[N][N];
int a[N][N],b[N][N];
int main() {
	read(n,L);
	rep(i,1,n){
		scanf("%s",s[i]+1);
		rep(j,1,n)if(s[i][j]=='#')a[i][j]=0;else a[i][j]=1;
	}
	rep(i,1,n){
		rep(j,1,n){
			int l=i,r=i+L-1;
			if(r<=n){
				bool ok=1;
				rep(k,l,r)if(a[k][j]==0){
					ok=0;
					break;
				}
				if(ok)rep(k,l,r)b[k][j]++;
			}
			l=j,r=j+L-1;
			if(r<=n){
				bool ok=1;
				rep(k,l,r)if(a[i][k]==0){
					ok=0;
					break;
				}
				if(ok)rep(k,l,r)b[i][k]++;
			}
		}
	}
	int px=1,py=1,an=0;
	rep(i,1,n){
		rep(j,1,n)if(b[i][j]>an){
			an=b[i][j];
			px=i;
			py=j;
		}
	}
	printf("%d %d\n",px,py);
	return 0;
}