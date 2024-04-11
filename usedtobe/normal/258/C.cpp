#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<set>
#include<map>
#define rep(i,a,b) for (int i=a;i<=b;++i)
#define dep(i,a,b) for (int i=a;i>=b;--i)
#define For(i,u) for (int i=H[u];i;i=nxt[i])
#define re(i,x) for (i=x.begin();i!=x.end();++i)
#define mp make_pair
#define pb push_back
#define TWO(x) (1<<(x))
#define N 100005
#define mod 1000000007
using namespace std;
template<class T> inline void read(T&x){bool fu=0;char c;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x=-x;};
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z){read(x);read(y);read(z);}
typedef long long ll;
typedef pair<int,int> pii;
ll pow(ll x,ll y){ll res=1;for(;y;y>>=1,x=x*x%mod)if(y&1)res=res*x%mod;return res;}
ll ans,res;
//head
int pp[N],p[N],c[N],n;
int main() {
	read(n);rep(i,1,n) {int x;read(x);c[x]++;};dep(i,N-5,1)c[i-1]+=c[i];
	for(int i=1;c[i];i++) {
		int x=0,y=0;res=1;
		for(int j=1;j*j<=i;++j) if (i%j==0){p[++x]=j;if(i-j*j)pp[++y]=i/j;}
		dep(j,y,1)p[++x]=pp[j];
		rep(j,2,x)
			res=res*pow(j-1,c[p[j-1]]-c[p[j]])%mod;
		ans=(ans+res*(pow(x,c[i])-pow(x-1,c[i])))%mod;
	}
	printf("%d\n",(ans+mod)%mod);
	return 0;
}