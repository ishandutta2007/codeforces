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

LL n,k,a,b;

int main(){
	//freopen("test.in","r",stdin);
	cin>>n>>k;
	cin>>a>>b;
	LL l1 = abs(b-a), l2 = abs(k-b-a);
	LL mi = 1e12, ma = 0;
	rep(i,0,n-1){
		mi = min(mi, n*k/__gcd(l1+i*k,n*k));
		mi = min(mi, n*k/__gcd(l2+i*k,n*k));
		ma = max(ma, n*k/__gcd(l1+i*k,n*k));
		ma = max(ma, n*k/__gcd(l2+i*k,n*k));
	}
	cout<<mi<<" "<<ma<<endl;
	return 0;
}