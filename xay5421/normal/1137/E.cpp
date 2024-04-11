#include<cstdio>
#include<algorithm>
#define fi first
#define se second
#define mp std::make_pair
typedef long long ll;
typedef std::pair<ll,ll> pll;
const int N=300005;
int n,m,top;pll a[N];ll k,b;
double slope(pll a,pll b){return 1.0*(a.se-b.se)/(a.fi-b.fi);}
ll calc(pll x){return k*x.fi+b+x.se;}
int main(){
	scanf("%d%d",&n,&m);a[top=1]=mp(0,0);
	for(int i=1,tp,k1,k2;i<=m;++i){
		scanf("%d%d",&tp,&k1);
		if(tp==1)a[top=1]=mp(0,0),k=b=0,n+=k1;else
		if(tp==2){
			pll now=mp(n,-(n*k+b));
			while(top>1&&slope(now,a[top])<=slope(a[top],a[top-1]))--top;
			a[++top]=now,n+=k1;
		}else{
			scanf("%d",&k2);
			b+=k1,k+=k2;
		}
		while(top>1&&calc(a[top])>=calc(a[top-1]))--top;
		printf("%lld %lld\n",a[top].fi+1,calc(a[top]));
	}
	return 0;
}