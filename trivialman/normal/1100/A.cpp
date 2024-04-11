#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define MP make_pair
#define PII pair<int, int>
typedef long long LL;
const LL P = 998244353;
const int INF = 0x3fffffff;
const int N = 200010;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,k,a[110];

int main(){
	//freopen("test.in","r",stdin);
	cin>>n>>k;
	rep(i,1,n) cin>>a[i];
	int ans = 0, sum = 0;
	rep(i,1,n) sum += a[i];
	rep(i,1,k){
		int tmp = 0;
		for(int x=i;x<=n;x+=k)tmp+=a[x];
		ans = max(ans, abs(sum - tmp));
	}
	cout<<ans<<endl;
	return 0;
}