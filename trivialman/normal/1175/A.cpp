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

int t;
LL n,k;

int main(){
	//freopen("test.in","r",stdin);
	cin>>t;
	while(t--){
		cin>>n>>k;
		LL ans = 0;
		while(n){
			ans += n % k + 1ll;
			n /= k;
		}
		cout<<ans-1<<endl;
	}
	return 0;
}