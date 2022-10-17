#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;
const int N=1000005;

int n,a[N];

ll tttmp[N],faker[N],kkk,sb,okok;

bool cmp(const int &a,const int &b){return a>b;}

ll check(){
	ll w=0; kkk=0;
	rep (i,1,n) kkk+=a[i],tttmp[i]=tttmp[i-1]+a[i];
	per (i,n,1) faker[i]=faker[i+1]+a[i];
	per (i,n,1){
		ll tmp=(ll)i*(i-1); int p=std::lower_bound(a+1+i,a+1+n,i,cmp)-a;
		tmp=tmp+(ll)(p-1-i)*i+faker[p];
		if (tttmp[i]-tmp>i){puts("-1"); exit(0);}
		w=std::max(w,tttmp[i]-tmp);
	}
	if ((kkk&1)^(w&1)) w++;
	return w;
}
int main(){
	scanf("%d",&n);
	rep (i,1,n) scanf("%d",&a[i]);
	std::sort(a+1,a+1+n,cmp);
	okok=check();
	std::reverse(a+1,a+1+n);
	rep (i,1,n) a[i]=n-a[i];
	sb=n-check();
	if (okok>sb) sb^=okok^=sb^=okok;
	for (ll i=okok;i<=sb&&i<=n;i+=2) printf("%I64d ",i);
	return 0;
}