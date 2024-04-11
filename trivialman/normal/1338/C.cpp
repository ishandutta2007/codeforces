#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int,2> 
#define vs vector<string>
typedef long long LL;
const LL P = 998244353;
const int N = 3005;
mt19937 rng(time(0));

int T;
LL n;
int f[4][4] = {{0,0,0,0},{0,1,2,3},{0,2,3,1},{0,3,1,2}};

int lg4(LL x){
	int num = 0;
	for(;(1ll<<num+num)<=x;num++);
	return num-1;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	
	cin>>T;
	while(T--){
		scanf("%lld",&n);
		int num = lg4(n);
		
		int md = (n-1) % 3 + 1;
		LL ans = md;
		n = (n - (1ll<<num+num) ) / 3;
		//cout<<ans<<" "<<n<<endl;
		rrep(i,num-1,0){
			ans <<= 2ll;
			ans += f[n>>(i+i)&3ll][md];
		}
		printf("%lld\n",ans); 
	}
	
	return 0;
}