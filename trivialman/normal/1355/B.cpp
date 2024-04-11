#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const int N = 2e5+5;
mt19937 rng(time(0));

int T;
int n, a[N];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	cin>>T;
	while(T--){
		cin>>n;
		rep(i,1,n) scanf("%d",a+i);
		sort(a+1,a+n+1);
		int ans = 0, cnt = 0;
		rep(i,1,n){
			cnt++;
			if(cnt>=a[i]){
				ans++, cnt = 0;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}