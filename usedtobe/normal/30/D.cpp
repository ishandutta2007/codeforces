#include<algorithm>
#include<cstdio>
#include<cmath>
#define rep(i,a,b) for (int i=a;i<=b;++i)
#define N 100005
using namespace std;
template<class T> inline void read(T&x){bool fu=0;char c;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x=-x;};
template<class T> inline void read(T&x,T&y){read(x);read(y);}
typedef long long ll;
int X,Y,k,n;
struct pt{int a,n;} x[N];
bool cmp(pt x,pt y) {return x.a<y.a;}
double dis(int i) {return sqrt((ll)(X-x[i].a)*(X-x[i].a)+(ll)Y*Y);}
double f(int l,int r) {return min(dis(r),dis(l))+x[r].a-x[l].a;}
double g(int t,int l,int r) {return min(dis(r)+x[r].a-x[l].a+x[t].a-x[l].a,x[r].a-x[l].a+x[r].a-x[t].a+dis(l));}
double work() {
	if (k==n+1) return f(1,n);
	int m=1;for (m=1;m<=n;++m)if (x[m].n==k) break;k=m;
	double ans=min(dis(k)+f(1,n),g(k,1,n));
	rep(i,k,n-1) ans=min(ans,f(i+1,n)+g(k,1,i));
	rep(i,2,k) ans=min(ans,f(1,i-1)+g(k,i,n));
	return ans;
}
int main() {
	read(n,k);rep(i,1,n)read(x[i].a),x[i].n=i;sort(x+1,x+n+1,cmp);
	read(X,Y);
	printf("%.10lf\n",work());
	return 0;
}