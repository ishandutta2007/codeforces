#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const int N = 1e5+5;
mt19937 rng(time(0));

int T, n;
int a[N];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	cin>>T;
	
	while(T--){
		scanf("%d",&n);
		rep(i,1,n) scanf("%d",a+i);
		int y = 0;
		rep(i,1,n) y ^= a[i];
		if (y==0) {
			printf("DRAW\n");
			continue;
		}
		
		while (__builtin_popcount(y) >= 2) y -= y&-y;
		int cnt = 0;
		rep(i,1,n) if(a[i]&y) cnt++;
		
		if (cnt%4==1 || cnt%4==3 && (n-cnt)%2==1){
			printf("WIN\n");
		}else printf("LOSE\n");
	}
	return 0;
}