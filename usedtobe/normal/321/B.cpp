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
#define N 1005
using namespace std;
template<class T> inline void read(T&x){bool fu=0;char c;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x=-x;};
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z){read(x);read(y);read(z);}
typedef long long ll;
typedef pair<int,int> pii;
//head
int ans,n,m,b[N];
multiset<int> S;
multiset<int>::iterator it;
struct card{int a,b;} a[N];
bool cmp1(card x,card y) {return x.b-10000*x.a<y.b-10000*y.a;}
bool cmp2(card x,card y) {return x.b+10000*x.a<y.b+10000*y.a;}
int main() {
	char s[50];
	read(n,m);rep(i,1,n)scanf("%s%d",s,&a[i].b),a[i].a=s[0]=='A';
	rep(i,1,m)read(b[i]);
	sort(a+1,a+n+1,cmp1);sort(b+1,b+m+1);rep(i,1,n) {
		if (a[i].a==0) break;
		if (b[m-i+1]>=a[i].b) ans+=b[m-i+1]-a[i].b;
		else break;
	}
	if (m>n) {
		rep(i,1,m)S.insert(b[i]);int tmp=0;
		sort(a+1,a+n+1,cmp2);
		rep(i,1,n) {
			if (a[i].a) it=S.lower_bound(a[i].b);
			else it=S.upper_bound(a[i].b);
			if (it==S.end()) return printf("%d\n",max(tmp,ans)),0;
			if (a[i].a)tmp+=(*it)-a[i].b;S.erase(it);
		}
		for(;S.size();S.erase(S.begin())) tmp+=*S.begin();
		ans=max(ans,tmp);
	}
	printf("%d\n",ans);
	return 0;
}