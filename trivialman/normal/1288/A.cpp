#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int,2>
typedef long long LL;
const LL P = 1e9+7;
const int INF = 0x3fffffff;
const int N = 505;
mt19937 rng(time(0));

int T, a, b, x;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	cin>>T;
	while(T--){
		cin>>b>>a;
		x = sqrt(a);
		int ans = 1e9;
		rep(i,x-2,x+2) if(i>=0) {
			ans = min(ans, i + (a+i) / (i+1) );
		}
		cout<<(ans<=b?"YES":"NO")<<endl;
	}
	return 0;
}