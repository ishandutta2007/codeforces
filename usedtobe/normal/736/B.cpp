#include<bits/stdc++.h>
#define rep(i,a,n) for(int _tmp=n,i=a;i<=_tmp;++i)
#define dep(i,a,n) for(int _tmp=n,i=a;i>=_tmp;--i)
#define re(i,a,n) for(int _tmp=n,i=a;i<_tmp;++i)
#define fec(i,a) for(__typeof a.begin() i=a.begin();i!=a.end();++i)
#define For(i,u) for(int i=H[u];i;i=nxt[i])
#define si(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define X first
#define Y second
using namespace std;
template<class T> inline void read(T&x){char c;bool fu=0;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x*=-1;}
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z) {read(x,y);read(z);}
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1000000007;
const int N=111111;
//head
ll n;
ll mul(ll x,ll y,ll z){
	x%=z,y%=z;
	if(z<=2e9)return (x*y%z+z)%z;
	return (x*y-(ll)(x/(long double)z*y+1e-3)*z+z)%z;
}
ll pow(ll p,ll n,ll mo)
{
	ll ans=1;
	for(;n;n>>=1,p=mul(p,p,mo))if(n&1)ans=mul(ans,p,mo);
	return ans;
}
bool check(ll n,ll a) {
	ll d=n-1,t;while(!(d&1))d>>=1;
	t=pow(a,d,n);while (d!=n-1&&t!=1&&t!=n-1) t=pow(t,2,n),d<<=1;
	return (t==n-1)||(d&1);
}
bool ok(int Ti,ll n) {
	if(n==2)return 1;if(n==1||!(n&1))return 0;
	while(Ti--)if(!check(n,rand()%(n-1)+1))return 0;
	return 1;
}
int main() {
	read(n);if((n&1)||n==2){
		if (ok(3,n))puts("1");
		else if(ok(3,n-2))puts("2");
		else puts("3");
	}else {
		puts("2");
	}
	return 0;
}