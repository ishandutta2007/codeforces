#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;
const LL MOD = 998244353;
const int INF = 0x3fffffff;
const int N = 100010;

struct dat{
	LL a,c,id;
}a[N];

LL t,d,m,n,id[N],tot=0;

bool cmp(dat x,dat y){return x.c<y.c||x.c==y.c&&x.id<y.id;}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d",&a[i].a),tot+=a[i].a;
	rep(i,1,n)scanf("%d",&a[i].c),a[i].id=i;
	sort(a+1,a+1+n,cmp);
	rep(i,1,n)id[a[i].id]=i;
	int j=0;
	rep(i,1,m){
		scanf("%d%d",&t,&d);
		LL ans=0;
		if(tot<d){
			tot=-1;
			printf("0\n");
			continue;
		}
		tot -= d;
		if(a[id[t]].a>=d){
			a[id[t]].a-=d;
			ans = d * a[id[t]].c;
		}else{
			ans = a[id[t]].a * a[id[t]].c;
			d -= a[id[t]].a;
			a[id[t]].a=0;
			while(j<=n&&a[j].a<d){
				ans += a[j].a*a[j].c;
				d -= a[j].a;
				a[j].a = 0;
				++j;
			}
			if(j<=n) ans+=a[j].c*d, a[j].a-=d;
		}
		printf("%lld\n",ans);
	}
	return 0;
}