#include<iostream>
#include<cstring>
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
#define TWO(x) (1<<(x))
#define N 1005
using namespace std;
template<class T> inline void read(T&x){bool fu=0;char c;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x=-x;};
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z){read(x);read(y);read(z);}
typedef long long ll;
typedef pair<int,int> pii;
//head
struct S{int num,val,id;} a[N];
bool operator<(S a,S b) {return a.val>b.val;}
struct tab{int cap,id;} b[N];
bool operator<(tab a,tab b){return a.cap<b.cap;}
int ans[N][2],n,k,cnt,V;
bool use[N];
int main() {
	read(n);rep(i,1,n)read(a[i].num,a[i].val),a[i].id=i;sort(a+1,a+n+1);
	read(k);rep(i,1,k)read(b[i].cap),b[i].id=i;sort(b+1,b+k+1);
	rep(i,1,n) {
		rep(j,1,k)if(!use[j]&&b[j].cap>=a[i].num) {
			++cnt;
			ans[cnt][0]=a[i].id;
			ans[cnt][1]=b[j].id;
			V+=a[i].val;use[j]=1;
			break;
		}
	}
	printf("%d %d\n",cnt,V);
	rep(i,1,cnt)printf("%d %d\n",ans[i][0],ans[i][1]);
	return 0;
}