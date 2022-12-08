#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<cstdio>
#include<cmath>
#include<stack>
#include<queue>
#include<set>
#include<map>
#define Re(i,x) for (i=x.begin();i!=x.end();++i)
#define For(i,u) for (int i=H[u];i;i=nxt[i])
#define re(i,a) for (int i=0;i<(int)a;++i)
#define rep(i,a,b) for (int i=a;i<=b;++i)
#define dep(i,a,b) for (int i=a;i>=b;--i)
#define POSIN(x,y) (x>=1&&x<=n&&y>=1&&y<=m)
#define clr(x) memset(x,0,sizeof x)
#define SZ(x) ((int)x.size())
#define TWO(x) (1<<(x))
#define mp make_pair
#define pb push_back
using namespace std;
template<class T> inline void read(T&x){bool fu=0;char c;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x=-x;};
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z){read(x);read(y);read(z);}
typedef long long ll;
typedef pair<int,int> pii;
//head
int main() {
	int now=0,cnt=0;
	int n;read(n);rep(i,1,n) {
		int x;read(x);
		if (x>0) now+=x;
		else if (now!=0) --now;
		else ++cnt;
	}
	cout<<cnt<<endl;
	return 0;
}