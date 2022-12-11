#include <set>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
#define max_n 100000
#define max_si 1000000000
int a[max_n+1];
ll sum[max_n+1];
set<int>st;
void slice(ci l,ci r){
	ll s=sum[r]-sum[l-1];
	if(s<=max_si)
		st.insert(s);
	int am=(a[l]+a[r])/2;
	int mid=upper_bound(a+l,a+r+1,am)-a;
	if(mid>r)
		return;
	slice(l,mid-1);
	slice(mid,r);
}
il void test(){
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1; i<=n; ++i)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	sum[0]=0;
	for(int i=1; i<=n; ++i)
		sum[i]=sum[i-1]+a[i];
	st.clear();
	slice(1,n);
	for(int x; q; --q){
		scanf("%d",&x);
		puts(st.count(x)?"Yes":"No");
	}
}
int main(){
//	test();
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}