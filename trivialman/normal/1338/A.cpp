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

int n, T, a[N];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	cin>>T;
	while(T--){
		scanf("%d", &n);
		rep(i,1,n) scanf("%d",a+i);
		int ma = -1e9, num = 0;
		rep(i,1,n){
			ma = max(ma, a[i]);
			num = max(num, ma - a[i]);
		}
		int ans = num==0 ? 0 : log2(num) + 1;
		printf("%d\n",ans);
	}
	return 0;
}