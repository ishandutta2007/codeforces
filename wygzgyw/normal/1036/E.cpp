#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=1010;
typedef long long ll;
int n;
ll ans;
set<pair<ll,ll> > s;
struct node {
	ll x1,y1,x2,y2;
} d[maxn];
ll gcd(ll a,ll b) {
	if (!a||!b) return a+b;
	return gcd(b,a%b);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) {
		read(d[i].x1),read(d[i].y1);
		read(d[i].x2),read(d[i].y2);
		ll x=abs(d[i].x1-d[i].x2),y=abs(d[i].y1-d[i].y2);
		ans+=gcd(x,y)+1;
	}
	for (int i=1;i<=n;i++) {
		s.clear();
		ll x1=d[i].x1,y1=d[i].y1,x2=d[i].x2,y2=d[i].y2;
		for (int j=1;j<i;j++) {
			ll x3=d[j].x1,y3=d[j].y1,x4=d[j].x2,y4=d[j].y2;
	double x=double((x1*y2-y1*x2)*(x3-x4)-(x3*y4-y3*x4)*(x1-x2))/double((x1-x2)*(y3-y4)-(y1-y2)*(x3-x4));
	double y=double((x1*y2-y1*x2)*(y3-y4)-(x3*y4-y3*x4)*(y1-y2))/double((x1-x2)*(y3-y4)-(y1-y2)*(x3-x4));
			if (x!=floor(x)||x<min(x1,x2)||x>max(x1,x2)||x<min(x3,x4)||x>max(x3,x4)
			||y!=floor(y)||y<min(y1,y2)||y>max(y1,y2)||y<min(y3,y4)||y>max(y3,y4)) continue;
			s.insert(make_pair(x,y));
		}
		ans-=s.size();
	}
	printf("%lld\n",ans);
	return 0;
}