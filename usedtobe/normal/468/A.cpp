#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<set>
#define X first
#define Y second
#define mp make_pair
#define ph push
#define pb push_back
#define rep(i,a,n) for (int i = a; i <= n; i+=2)
#define dep(i,a,n) for (int i = a; i >= n; i+=2)
#define re(b,a) for(a::iterator it=b.begin();it!=b.end();++it)
#define eps 1e-8
#define lowbit(x) (x&(-x))
#define pi 3.1415926535897
#define sqr(x) ((x)*(x))
#define MAX(a,b) a=max(a,b)
#define MIN(a,b) a=min(a,b)
#define SZ(x) ((int)(x).size())
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))
#define all(x) (x).begin(),(x).end()
#define inf 0x7fffffff
#define mod 1000000007
template<class T> inline void read(T&x){bool fu=0;char c;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x=-x;};
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z){read(x,y);read(z);}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int main() {
	int n;
	scanf("%d",&n);
	if(n<=3)puts("NO");
	else{
		puts("YES");
	 	if(n&1) {
		 	rep(i,6,n)printf("%d - %d = %d\n",i+1,i,1);
			puts("5 * 4 = 20");
			puts("20 + 3 = 23");
			puts("23 + 2 = 25");
			puts("25 - 1 = 24");
			rep(i,6,n)puts("24 * 1 = 24");
		}
		else{
			rep(i,5,n)printf("%d - %d = %d\n",i+1,i,1);
			puts("4 * 3 = 12");
			puts("12 * 2 = 24");
			puts("24 * 1 = 24");
			rep(i,5,n)puts("24 * 1 = 24");
	 	}
	}
	return 0;
}