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

int T, n, k;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	cin>>T;
	while(T--){
		cin>>n>>k;
		if(n>=k && (n-k)%2==0){
			printf("YES\n");
			rep(i,1,k-1) printf("1 ");
			printf("%d\n",n-k+1);
		}else if(n>=2*k && (n-k*2)%2==0){
			printf("YES\n");
			rep(i,1,k-1) printf("2 ");
			printf("%d\n",n-(k-1)*2);
		}else printf("NO\n");
	}
	return 0;
}