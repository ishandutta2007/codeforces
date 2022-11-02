#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll INF=1e18;
ll X0,Y0,ax,ay,bx,by,s,t,T,tmp;
int tot,ans;
struct node { ll x,y; } d[100],A,B;
int main() {
//	freopen("1.txt","r",stdin);
	read(X0); read(Y0);
	read(ax); read(ay);
	read(bx); read(by);
	d[++tot]=(node){X0,Y0};
	read(s); read(t); read(T);
	while (1) {
		A=d[tot];
		if ((INF-bx)/ax<A.x) break;
		if ((INF-by)/ay<A.y) break;
		B.x=A.x*ax+bx;
		B.y=A.y*ay+by;
		d[++tot]=B;
	}
//	for (int i=1;i<=tot;i++) printf("%lld %lld\n",d[i].x,d[i].y);
	for (int i=1;i<=tot;i++) {
		tmp=abs(s-d[i].x)+abs(t-d[i].y);
		for (int j=i;j<=tot;j++) {
			if (tmp<=T) ans=max(ans,j-i+1);
			else break;
			if (j==tot) break;
			tmp+=abs(d[j+1].x-d[j].x)+abs(d[j+1].y-d[j].y);
		}
	}
	reverse(d+1,d+tot+1);
	for (int i=1;i<=tot;i++) {
		tmp=abs(s-d[i].x)+abs(t-d[i].y);
		for (int j=i;j<=tot;j++) {
			if (tmp<=T) ans=max(ans,j-i+1);
			else break;
			if (j==tot) break;
			tmp+=abs(d[j+1].x-d[j].x)+abs(d[j+1].y-d[j].y);
		}
	}
	printf("%d\n",ans);
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Interger overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/