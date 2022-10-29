#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL MOD = 998244353;
const int N = 1e6+10;

struct dat{
	LL x,y,c;
}a[N];
int n;
LL dp[N], ans=0;
deque<int> vals;

LL calc1(int j, int i){
	return dp[j]+(a[i].x-a[j].x)*a[i].y-a[i].c;
}
double calc2(int j, int i){
	return 1.0*(dp[i]-dp[j])/(a[i].x-a[j].x);
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
	scanf("%d",&n);
	rep(i,1,n)scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].c);
	sort(a+1,a+n+1,[](dat x, dat y){return x.x<y.x;});
	vals.push_back(0);
	rep(i,1,n){
		while(vals.size()>1 && calc1(vals.front(), i) < calc1(*(vals.begin()+1), i)) vals.pop_front();
		ans = max(ans, dp[i] = calc1(vals.front(), i) );
		while(vals.size()>1 && calc2(vals.back(), i) > calc2(*(vals.rbegin()+1), i)) vals.pop_back();
		vals.push_back(i);
	}
	printf("%lld\n",ans);
	return 0;
}