#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define repr(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL MOD = 998244353;
const int N = 100010;

LL n,k,A,B,a[N];

LL dfs(int l, int r, int start, int n){
	if(l>r)return A;
	if(n==0)return B*(r-l+1);
	int mid = start+(1<<n-1);
	int pos = lower_bound(a+l,a+r+1,mid+1)-a-1;
	//cout<<*lower_bound(a+l,a+r+1,mid+1)<<endl;
	LL lres = dfs(l, pos, start, n-1), rres = dfs(pos+1, r, mid, n-1);
	//printf("n=%d l=%d r=%d mid=%d pos=%d\n",n,l,r,mid,pos);
	//cout<<lres<<" "<<rres<<endl;
	return min(lres+rres, B*(r-l+1)<<n);
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
	scanf("%lld%lld%lld%lld",&n,&k,&A,&B);
	rep(i,1,k)scanf("%d",a+i);
	sort(a+1,a+k+1);
	printf("%lld\n",dfs(1,k,0,n));
	return 0;
}