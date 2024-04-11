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
const int N=211111,LEN=4;
//head
int a[N],d[N],n;
ll ans;
int check(ll x){
	rep(i,1,n){
		if(x<1900&&d[i]==1)return 2;
		if(x>=1900&&d[i]==2)return 0;
		x+=a[i];
	}
	ans=x;
	return 1;
}
int main() {
	read(n);int now=0;
	rep(i,1,n)read(a[i],d[i]);
	ll L=-inf,R=inf;if(d[1]==1)L=1900;else R=1899;
//	if(check(R))L=R;
//	if(check(L))R=L;
	while(L<R){
		ll md=(L+R+1)/2;
		if(check(md)==2)L=md+1;
		else if(check(md)==1)L=md;
		else R=md-1;
	}
	if(R==inf&&check(R)==1)puts("Infinity");
	else if(check(L)!=1)puts("Impossible");
	else cout<<ans;
	return 0;
}