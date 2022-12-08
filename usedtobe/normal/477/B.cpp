#include<cstring>
#include<cstdio>
#include<algorithm>
#include<set>
#include<cmath>
#include<vector>
#include<map>
#include<iostream>
#define rep(i,a,b) for (int i=a;i<=b;++i)
#define For(i,u) for (int i=H[u];i;i=nxt[i])
#define re(it,a) for (it=a.begin();it!=a.end();++it)
#define mod 1000000007 
#define pb push_back
#define all(x) x.begin(),x.end()
#define mp make_pair
#define X first
#define Y second
using namespace std;
template<class T> inline void read(T&x){bool fu=0;char c;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x=-x;};
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z){read(x,y);read(z);}
typedef long long ll;
typedef pair<int,int> pii;
//head
int n,k;
int main() {
	read(n,k);printf("%d\n",(6*n-1)*k);
    rep(i,1,n)printf("%d %d %d %d\n",(6*i-5)*k,(6*i-3)*k,(6*i-2)*k,(6*i-1)*k);
	return 0;
}