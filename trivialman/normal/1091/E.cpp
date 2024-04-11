#include<bits/stdc++.h>
using namespace std;
#define N 500010
#define LL long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)

int a[N], b[N], n, lb, rb, odd;

int check(int x){
	if(x==-1)return 0;
	int m = n + 1, i, ans = 0;
	LL LHS=0, RHS=0, rsum=0, rind=m;
	for(i=m;i>1&&a[i-1]<=x;--i) a[i]=a[i-1];
	a[i] = x;
	rep(k,1,m){
		LHS += a[k];
		for(;rind>k&&a[rind]<k;--rind)rsum += a[rind];
		RHS = 1ll * k * (k-1) + max(0ll, rind-k) * k + rsum;
		if(LHS>RHS){
			ans = a[k]<=x?1:-1;
			break;
		}
	}
	for(;i<m;++i) a[i] = a[i+1];
	return ans;
}
bool comp(int x, int y){return check(x)<check(y);}

int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",a+i), odd^=(a[i]&1);
	sort(a+1, a+n+1, [](int x,int y){return x>y;});
	rep(i,0,n)b[i]=i;
	lb = lower_bound(b,b+n+1,-1,comp)-b;
	rb = upper_bound(b,b+n+1,-1,comp)-b-1;
	if ( lb>rb || lb==rb && (lb+odd&1) ) cout<<-1<<endl;
	else rep(i,lb,rb)if(!(i+odd&1))cout<<i<<" ";
	return 0;
}