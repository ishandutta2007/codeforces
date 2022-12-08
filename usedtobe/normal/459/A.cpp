#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#define rep(i,a,b) for (int i=a;i<=b;++i)
#define dep(i,a,b) for (int i=a;i>=b;--i)
#define foreach(e,x) for (typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define INF 0x7fffffff
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
template<class T> inline void read(T&x){bool fu=0;char c;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x=-x;};
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z){read(x,y);read(z);}
int main() {
	int x1,x2,y1,y2;
	read(x1,y1);read(x2,y2);
	if (y1==y2) {
		if (x1>x2) swap(x1,x2);
		int t=x2-x1;
		printf("%d %d %d %d\n",x1,y1+t,x2,y2+t);
	} else if (x1==x2) {
		if (y1>y2) swap(y1,y2);
		int t=y2-y1;
		printf("%d %d %d %d\n",x1+t,y1,x2+t,y2);
	} else {
		if (abs(y2-y1)!=abs(x2-x1)) return puts("-1"),0;
		if (x1>x2) swap(x1,x2),swap(y1,y2);
		if (y1>y2) printf("%d %d %d %d\n",x1,min(y1,y2),x2,max(y1,y2));
		else printf("%d %d %d %d\n",x1,y2,x2,y1);
	}
	return 0;
}