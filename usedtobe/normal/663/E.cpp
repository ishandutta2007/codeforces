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
const int N=1<<20;
//head
ll cnt[N],f[N];
char s[N];
int n,m,a[N];
void fwt(ll *a,int len){
	if(len==1)return;
	int h=len>>1;
	fwt(a,h);fwt(a+h,h);
	re(i,0,h){
		ll x=a[i],y=a[i+h];
		a[i]=x+y;
		a[i+h]=x-y;
	}
}
void ifwt(ll *a,int len){
	if(len==1)return;
	int h=len>>1;
	re(i,0,h){
		ll x=a[i],y=a[i+h];
		a[i]=(x+y)/2;
		a[i+h]=(x-y)/2;
	}
	ifwt(a,h);ifwt(a+h,h);
}
int main() {
	read(n,m);
	rep(i,1,n){
		scanf("%s",s+1);
		rep(j,1,m)if(s[j]=='1')a[j]|=1<<i-1;
	}
	rep(i,1,m)cnt[a[i]]++;
	re(i,0,1<<n){
		int b=__builtin_popcount(i);
		f[i]=min(b,n-b);
	}
	fwt(cnt,1<<n);
	fwt(f,1<<n);
	re(i,0,1<<n)f[i]*=cnt[i];
	ifwt(f,1<<n);
	ll ans=1<<30;
	re(i,0,1<<n)ans=min(ans,f[i]);
	cout<<ans;
	return 0;
}