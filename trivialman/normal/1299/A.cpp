#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int,2>
typedef long long LL;
const LL P = 1e9+7;
const int INF = 0x3fffffff;
const int N = 1e5+5;
mt19937 rng(time(0));

int n, a[N], cnt[50];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",a+i);
	rep(i,1,n){
		rep(j,0,30) if(a[i]>>j&1) {
			++cnt[j];
		}
	}
	int maxa = 0, maxi = 1;
	rep(i,1,n){
		int ans = 0;
		rep(j,0,30) if(a[i]>>j&1) {
			if(cnt[j]==1) ans += (1<<j);
		}
		if(ans>maxa){
			maxa = ans, maxi = i;
		}
		//cout<<a[i]<<" "<<ans<<endl;
	}
	swap(a[1], a[maxi]);
	rep(i,1,n) printf("%d ",a[i]);
	return 0;
}