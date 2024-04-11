#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2010;
struct node {
	ll x,y;
} a[maxn],p[maxn],q[maxn];
node operator - (const node &a,const node &b) {
	return (node){a.x-b.x,a.y-b.y};
}
ll operator / (const node &a,const node &b) {
	return a.x*b.y-a.y*b.x;
}
bool cmp(node a,node b) {
	return a/b>0;
}
int n,P,Q;
ll ans;
ll f(ll x) {
	return x*(x-1)/2;
}
int main() {
//	freopen("1.txt","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld %lld",&a[i].x,&a[i].y);
	for (int i=1;i<=n;i++) {
		P=Q=0;
		for (int j=1;j<=n;j++) {
			if (i==j) continue;
			node tmp=a[j]-a[i];
			if (tmp.y>0||(tmp.y==0&&tmp.x>0)) p[++P]=tmp;
			else q[++Q]=tmp;
		}
		if (P) sort(p+1,p+(P+1),cmp);
		if (Q) sort(q+1,q+(Q+1),cmp);
		int pos=0;
		for (int j=1;j<=P;j++) {
			while (pos<Q&&p[j]/q[pos+1]>0) pos++;
			ans+=f(pos+P-j)*f(j-1+Q-pos);
		}
	}
	printf("%lld\n",ans);
	return 0;
}