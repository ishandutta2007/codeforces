#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
#define PII pair<int,int>
typedef long long LL;
const LL P = 1e9+7;
const int N = 2e5+5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,a[N];

int main(){
	//freopen("test.in","r",stdin);
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",a+i);
	LL ans = 0;
	int x = 1e9+5;
	rrep(i,n,1){
		if(x>0) x = min(x-1,a[i]);
		ans += 1ll * x;
	}
	cout<<ans<<endl;
	return 0;
}