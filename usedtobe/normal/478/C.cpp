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
using namespace std;
template<class T> inline void read(T&x){bool fu=0;char c;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x=-x;};
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z){read(x);read(y);read(z);}
typedef long long ll;
typedef pair<int,int> pii;
//head
ll a[5];
int main() {
	rep(i,1,3)read(a[i]);sort(a+1,a+3+1);
	if ((a[1]+a[2])*2<a[3]) cout<<a[1]+a[2]<<endl;
	else cout<<(a[1]+a[2]+a[3])/3<<endl;
	return 0;
}