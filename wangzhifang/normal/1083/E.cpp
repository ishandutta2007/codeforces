#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
#define cs const
#define il __inline__ __attribute__((always_inline))
#define max_n 1000000
struct node{
	int x,y;
	ll v;
	il bool operator<(cs node&n)cs{
		return x<n.x;
	}
};
node a[max_n+1];
int q[max_n+1];
ll dp[max_n+1];
double slope(int i,int j){
	return double(dp[i]-dp[j])/(a[i].x-a[j].x);
}
int main(){
	int n,ql,qr;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d%d%lld",&a[i].x,&a[i].y,&a[i].v);
	sort(a+1,a+n+1),ql=qr=1;
	for(int i=1; i<=n; ++i){
		for(; ql<qr&&slope(q[ql],q[ql+1])>=a[i].y; ++ql);
		int j=q[ql];
		dp[i]=max(dp[i-1],dp[j]+ll(a[i].y)*(a[i].x-a[j].x)-a[i].v);
		for(; ql<qr&&slope(q[qr-1],q[qr])<=slope(q[qr],i); --qr);
		q[++qr]=i;
	}
	printf("%lld\n",dp[n]);
	return 0;
}