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
int ex,ey,a,b;
bool check(int x,int y,int a,int b) {
	if (a==x&&b==y) return 1;
	if (ex==0||ey==0) {
		if (ex==0&&ey==0) return 0;
		if (ex==0) if (a==x&&(b-y)%ey==0&&(b-y)/ey>0) return 1;
		if (ey==0) if (b==y&&(a-x)%ex==0&&(a-x)/ex>0) return 1;
		return 0;
	}
	if ((a-x)%ex!=0||(b-y)%ey!=0) return 0;
	if ((a-x)/ex!=(b-y)/ey) return 0;
	if ((a-x)/ex<0||(b-y)/ey<0) return 0;
	return 1;
}
int main() {
	read(a,b);int x=0,y=0;char s[10005];
	scanf("%s",s+1);int n=strlen(s+1);
	rep(i,1,n) {
		if(s[i]=='L')x--;
		if(s[i]=='R')x++;
		if(s[i]=='U')y++;
		if(s[i]=='D')y--;
	}
	ex=x,ey=y;x=0;y=0;if (check(x,y,a,b)) return puts("Yes"),0;
	rep(i,1,n) {
		if(s[i]=='L')x--;
		if(s[i]=='R')x++;
		if(s[i]=='U')y++;
		if(s[i]=='D')y--;
		if (check(x,y,a,b)) return puts("Yes"),0;
	}
	puts("No");
	return 0;
}