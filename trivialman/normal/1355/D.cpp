#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
typedef long long LL;
const int P = 998244353;
const int N = 2e5+5;
const double PI = acos(-1);
mt19937 rng(time(0));

int T, n, s;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	
	cin>>n>>s;
	if(n*2>s){
		printf("NO\n");
	}else{
		printf("YES\n");
		rep(i,1,n-1) printf("%d ",1);
		printf("%d\n",s-n+1);
		printf("%d\n",s/2);
	}
	
	return 0;
}