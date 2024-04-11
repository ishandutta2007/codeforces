#include<bits/stdc++.h>
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
#define inf 1000000000
#define fail return puts("NO"),0
using namespace std;
template<class T> inline void read(T&x){char c;bool fu=0;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x*=-1;}
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z) {read(x,y);read(z);}
template<class T> inline void MAX(T&x,T y){if(x<y)x=y;}
template<class T> inline void MIN(T&x,T y){if(x>y)x=y;}
typedef long long ll;
typedef pair<int,int> pii;
const int N=111111,LEN=4;
//head
int n,ans,m,d;
char dir[N];
int main() {
	scanf("%d",&n);int x=0,y=0;
	rep(_,1,n){
		scanf("%d%s",&d,dir);
		if(x==0){
			if(dir[0]!='S')fail;
		}
		if(x==20000){
			if(dir[0]!='N')fail;
		}
		if(dir[0]=='S'){
			x+=d;
			if(x>20000)fail;
		}else if(dir[0]=='E'){
			y+=d;
		}else if(dir[0]=='N'){
			x-=d;
			if(x<0)fail;
		}else {
			y-=d;
		}
	}
	if(x!=0)fail; 
	puts("YES");
	return 0;
}