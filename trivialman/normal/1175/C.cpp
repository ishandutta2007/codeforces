#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
#define PII pair<int, int>
typedef long long LL;
const LL P = 998244353;
const int N = 2e5+10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int T,n,k,a[N];

int main(){
	//freopen("test.in","r",stdin);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		rep(i,1,n)scanf("%d",a+i);
		int mi = 1;
		rep(i,1,n-k){
			if(a[i+k]-a[i]<a[mi+k]-a[mi]) mi = i;
		}
		printf("%d\n",(a[mi+k]+a[mi])/2);
	}
	return 0;
}