#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int,2>
typedef long long LL;
const LL P = 1e9+7;
const LL INF = 1e18;
const int N = 1e5+5;
mt19937 rng(time(0));
 
int n, d, m, x, n1, n2;
LL a[N], b[N];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	
	scanf("%d%d%d",&n,&d,&m);
	rep(i,1,n) {
		scanf("%d",&x);
		if(x>m) b[++n2] = x;
		else a[++n1] = x;
	}
	
	sort(a+1,a+n1+1), reverse(a+1,a+n1+1);
	sort(b+1,b+n2+1), reverse(b+1,b+n2+1);
	rep(i,1,n1) a[i] += a[i-1];
	rep(i,1,n2) b[i] += b[i-1];
	
	LL ans = 0;
	rep(i,0,n2){
		//keep i elements in b
		int na = n - (i + (i-1) * d);
		if (na<0) break;
		ans = max(ans, b[i] + a[min(na, n1)]);
	}
	cout<<ans<<endl;
	return 0;
}