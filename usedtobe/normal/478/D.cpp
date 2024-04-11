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
int s(int x) {return x*(x+1)/2;}
void add(int &a,int b) {a+=b;if (a>mod) a-=mod;} 
int h,r,g,f[N],S,ans;
int main() {
	read(r,g);if (r>g) swap(r,g);f[0]=1;
	rep(i,1,1000) if (s(i)<=r+g) h=i;
	S=s(h);rep(i,1,h)dep(j,r,i)add(f[j],f[j-i]);
	rep(i,0,r)if(i+g>=S) add(ans,f[i]);
	printf("%d\n",ans);
	return 0;
}