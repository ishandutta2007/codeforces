#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define CL(a,x) memset(a, x, sizeof(a))
#define MP make_pair
#define PB push_back
#define PII pair<int, int>
typedef long long LL;
const LL P = 998244353;
const int N = 2e5+5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct dat{
	LL t,c;
	int i;
	bool operator<(dat y) const {return this->t>y.t;}
};
priority_queue<dat> heap0;
LL a[N],b[N];
int n,k;

bool check(LL m){
	priority_queue<dat> heap = heap0;	
	rep(j,1,k-1){
		if(heap.empty()) return true;
		dat x = heap.top();
		heap.pop();
		
		if(x.t<j-1) return false;
		int i = x.i;
		x.c += m;
		x.t = x.c/b[i];
		if(x.t<j) return false;
		if(x.t<k) heap.push(x);
	}
	if(!heap.empty() && heap.top().t<k-1) return false;
	return true;
} 

int main(){
	//freopen("test.in","r",stdin);
	scanf("%d%d",&n,&k);
	rep(i,1,n)scanf("%I64d",a+i);
	rep(i,1,n)scanf("%I64d",b+i);
	rep(i,1,n)if(a[i]/b[i]<1ll*k)heap0.push({a[i]/b[i],a[i],i});
	
	LL l = 0, r = 2e12, ans = 2e12;
	while(l<=r){
		LL mid = l+r>>1;
		if(check(mid)){
			r = mid - 1;
			ans = min(ans, mid);
		}else{
			l = mid + 1;
		}
	}
	printf("%I64d\n",ans==2e12?-1:ans);
	return 0;
}