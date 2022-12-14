#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
typedef double f2;
#define mem1(x) memset(x,0,sizeof(x))
#define mem2(x) memset(x,0x3f,sizeof(x))
#define eps 1e-7
f2 fabs(f2 x){return x>0?x:-x;}
#define N 200050
f2 w[N],x[N],y[N],k,b,vx[N],vy[N];
int n;
ll ans;
map<f2,int>f;
map<pair<f2,f2>,int>f3;
int inq(f2 x) {
	if(f.count(x)) return f[x];
	return 0;
}
void insert(f2 x) {
	f[x]++;
}
int main() {
	scanf("%d%lf%lf",&n,&k,&b);
	int i;
	for(i=1;i<=n;i++) {
		scanf("%lf%lf%lf",&x[i],&vx[i],&vy[i]);
		w[i]=k*vx[i];
	}
	for(i=1;i<=n;i++) {
		f2 tmp=vy[i]-w[i];
		ans+=inq(tmp);
		insert(tmp);
	}
	for(i=1;i<=n;i++) {
		if(f3.count(make_pair(vx[i],vy[i]))) ans-=f3[make_pair(vx[i],vy[i])];
		f3[make_pair(vx[i],vy[i])]++;
	}
	printf("%I64d\n",ans*2);
}