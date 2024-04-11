#include <cstdio>
#include <algorithm>
#define MAXN 105

typedef long long ll;
int n;
ll a[MAXN];

inline ll get_3(ll x){
	int res=0;
	while (x%3==0) x/=3,res++;
	return res;
}

inline bool cmp(const ll &x,const ll &y){
	return get_3(y)<get_3(x) || (get_3(x)==get_3(y) && x<y); 
}

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld",a+i);
	std::sort(a+1,a+1+n,cmp);
	for (int i=1;i<=n;i++) printf("%lld ",a[i]);
	return 0;
}