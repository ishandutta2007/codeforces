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
#define M 1000000009
#define N 100005
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
int n;
char s[50][50]={"",
"0+------------------------+",
"0|#.#.#.#.#.#.#.#.#.#.#.|D|)",
"0|#.#.#.#.#.#.#.#.#.#.#.|.|",
"0|#.......................|",
"0|#.#.#.#.#.#.#.#.#.#.#.|.|)",
"0+------------------------+"
};
int main() {
	read(n);
	rep(i,1,min(4,n))s[i+1][2]='O';
	for(int i=5,r=2,c=4;i<=n;++i){s[r][c]='O';if(++r==4)++r;if(r==6)r=2,c+=2;}
	for(int i=1;i<=6;++i)printf("%s\n",s[i]+1);
	return 0;
}