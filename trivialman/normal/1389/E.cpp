#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const int P = 1000000007;
const int INF = 1e9;
const int N = 1e6+5;
const double pi = acos(-1);
mt19937 rng(time(0));

int T;
LL m,d,w;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	
	cin>>T;
	while(T--){
		cin>>m>>d>>w;
		w /= __gcd(w, d-1);
		m = min(m,d);
		LL k = m / w;
		cout<<k*(m*2-(k+1)*w)/2<<endl;
	}
	return 0;
}