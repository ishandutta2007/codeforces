#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
typedef long long LL;
const LL P = 998244353;
const int INF = 0x3fffffff;
const int N = 1005;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, p, ans = -1;

int main(){
	//freopen("test.in","r",stdin);
	cin>>n>>p;
	rep(i,1,100){
		int x = n-p*i;
		if(x>=i && __builtin_popcount(x)<=i){
			ans = i; break;
		}
	}
	cout<<ans<<endl;
	return 0;
}