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

int T, n, k;

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	
	cin>>T;
	while(T--){
		cin>>n>>k;
		LL l=1, r=k*2, ans=0;
		while(l<=r){
			LL mid = l+r>>1;
			if(mid-mid/n>=k){
				ans = mid; r = mid-1;
			}else l = mid+1;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}