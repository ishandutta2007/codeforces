#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
#define PII pair<int, int>
typedef long long LL;
const LL P = 998244353;
const int N = 1e5+10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int n, x, y, a[N], b[N], p[N];
 
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",a+i),p[i]=i;
	while(clock()<399){
		shuffle(p+1,p+n+1,rng);
		x = a[p[1]], y = a[p[2]];
		b[p[1]] = 1, b[p[2]] = 2;
		rep(i,3,n)if(__gcd(x,a[p[i]])<x){
			x = __gcd(x, a[p[i]]);
			b[p[i]] = 1;
		}else{
			y = __gcd(y, a[p[i]]);
			b[p[i]] = 2;
		}
		if(x==1 && y==1){
			printf("YES\n");
			rep(i,1,n)printf("%d ",b[i]);
			return 0;
		}
	}
	printf("NO");
	return 0;
}