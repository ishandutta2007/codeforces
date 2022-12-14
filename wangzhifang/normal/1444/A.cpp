#include <cstdio>
using namespace std;
#define cs const
#define st static
#define il inline
#define tpl template
#define tpn typename
typedef long long ll;
tpl<tpn T1,tpn T2>il void maxify_il(T1&x,cs T2&y){
	y>x&&(x=y);
}
int main(){
	int t;
	ll p;
	int q;
	scanf("%d",&t);
	do{
		scanf("%lld%d",&p,&q);
		if(p%q){
			printf("%lld\n",p);
			continue;
		}
		int tmp=q;
		ll ans=1;
		for(int x=2; x*x<=tmp; ++x){
			if(!(tmp%x)){
				long long now=p;
				while(!((now/=x)%q));
				maxify_il(ans,now);
				while(!((tmp/=x)%x));
			}
		}
		if(tmp>1){
			while(!((p/=tmp)%q));
			maxify_il(ans,p);
		}
		printf("%lld\n",ans);
	}while(--t);
	return 0;
}