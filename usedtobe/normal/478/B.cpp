#include<iostream>
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
#define mod 1000000007
#define N 500005
using namespace std;
template<class T> inline void read(T&x){bool fu=0;char c;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x=-x;};
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z){read(x);read(y);read(z);}
typedef long long ll;
typedef pair<int,int> pii;
//head
ll n,m,gg,x,y;
ll s(ll a) {return a*(a-1)/2;}
int main() {
	read(n,m);gg=n/m;y=n%m;x=m-y;
	cout<<x*s(gg)+y*s(gg+1)<<" "<<s(n-m+1)<<endl;
	return 0;
}