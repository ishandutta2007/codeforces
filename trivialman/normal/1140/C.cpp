#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL MOD = 1e9+7;
const int N = 300010;

struct dat{
	LL t,b;
}a[N];
int n, k;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	scanf("%d%d",&n,&k);
	rep(i,1,n)scanf("%d%d",&a[i].t,&a[i].b);
	sort(a+1,a+n+1,[](dat x, dat y){return x.b>y.b;});
	priority_queue<LL> heap;
	LL ans=0,sum=0;
	rep(i,1,n){
		sum+=a[i].t;
		heap.push(-a[i].t);
		if(heap.size()>k){
			//cout<<heap.top()<<endl;
			sum+=heap.top();
			heap.pop();
		}
		ans = max(ans, sum*a[i].b);
	}
	printf("%lld\n",ans);
	return 0;
}