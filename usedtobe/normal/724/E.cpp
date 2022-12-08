#include<bits/stdc++.h>
#define rep(i,a,n) for(int _tmp=n,i=a;i<=_tmp;++i)
#define dep(i,a,n) for(int _tmp=n,i=a;i>=_tmp;--i)
#define fec(i,a) for(__typeof a.begin() i=a.begin();i!=a.end();++i)
#define For(i,u) for(int i=H[u];i;i=nxt[i])
#define re(i,a,b) for (int i=a;i<b;++i)
#define si(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define X first
#define Y second
using namespace std;
template<class T> inline void read(T&x){char c;bool fu=0;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x*=-1;}
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z) {read(x,y);read(z);}
typedef unsigned long long ll;
typedef pair<int,int> pii;
const int N=11111;
const ll inf=ll(-1ll);
ll p[N],s[N];
int n;
ll f[2][N],c;
int main() {
	read(n);read(c);
	rep(i,1,n)read(p[i]);
	rep(i,1,n)read(s[i]);
	f[0][0]=0;
	rep(i,0,n-1){
		rep(j,0,i+1)f[(i+1)&1][j]=inf;
		rep(j,0,i){
			f[(i+1)&1][j+1]=min(f[(i+1)&1][j+1],f[i&1][j]+s[i+1]);
			f[(i+1)&1][j]=min(f[(i+1)&1][j],f[i&1][j]+1ll*j*c+p[i+1]);
		}
	}
	ll ans=inf;
	rep(i,0,n)ans=min(ans,f[n&1][i]);
	cout<<ans<<endl;
	return 0;
}