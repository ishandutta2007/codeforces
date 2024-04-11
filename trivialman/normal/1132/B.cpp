#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
#define PII pair<int,int>
typedef long long LL;
const LL P = 1e9+7;
const int N = 3e5+5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,m,a[N],x;

int main(){
	//freopen("test.in","r",stdin);
	scanf("%d",&n);
	LL sum = 0;
	rep(i,1,n)scanf("%d",a+i),sum+=1ll*a[i];
	sort(a+1,a+n+1);reverse(a+1,a+n+1);
	scanf("%d",&m);
	rep(i,1,m){
		scanf("%d",&x);
		printf("%lld\n",sum-1ll*a[x]);
	}
	return 0;
}