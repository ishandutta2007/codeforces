#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef const int& ci;
#define max_n 200000
#define mod 1000000007
pair<int,pair<int,int> >a[max_n+2];
int pos[max_n+1];
int tr[max_n+1];
int query(int p,ci n){
//	printf("%d %d\n",p,n);
	p=n-p+1;
	ll ret=tr[p];
	for(; p&=p-1; ret+=tr[p]);
	return ret%mod;
}
void mod1(int&x){
	x>=mod&&(x-=mod);
}
void update(int p,ci v,ci n){
	p=n-p+1;
	for(mod1(tr[p]+=v); (p+=(p&(-p)))<=n; mod1(tr[p]+=v));
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d%d",&a[i].second.first,&a[i].first),a[i].second.second=0;
	int m;
	scanf("%d",&m);
	for(int x; m; --m,a[x].second.second=1)
		scanf("%d",&x);
	sort(a+1,a+n+1);
	for(int i=1; i<=n; ++i){
//		printf("%d %d %d\n",a[i].second.first,a[i].first,a[i].second.second);
		a[i].first=a[i].second.first;
		a[i].second.first=i;
	}
	sort(a+1,a+n+1);
	for(int i=1; i<=n; ++i)
		pos[a[i].second.first]=i;
	int lst=0;
	for(int i=n; i; --i)
		if(a[i].second.second&&a[lst].second.first<a[i].second.first){
			a[lst].second.second=i;
			lst=i;
//			printf("%d(%d)\n",i,a[i].second.first);
		}
		else
			a[i].second.second=0;
	a[lst].second.second=1;
	ll ans=0;
	for(int i=1; i<=n; ++i){
		int p=pos[i];
		if(a[p].second.second)
			ans+=query(a[p].second.second,n)+1;
//		puts("adf");
		int v=query(p,n)+1;
//		printf("%d: %d %d\n",i,p,v);
		update(p,v,n);
	}
	printf("%lld\n",ans%mod);
	return 0;
}