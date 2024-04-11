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
		int pre = 0, na = 0, nb = 0, i = 1, j = n, num, move = 0;
		while(1){
			num = 0;
			for(;i<=j&&num<=pre;i++) num+=a[i];
			move++, na+=num;
			if(i>j) break;
			pre=num;
			
			num = 0;
			for(;i<=j&&num<=pre;j--) num+=a[j];
			move++, nb+=num;
			if(i>j) break;
			pre=num;
		} 
		printf("%d %d %d\n", move, na, nb);
	}
	
	return 0;
}