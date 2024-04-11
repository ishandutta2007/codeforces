#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const int P = 998244353;
const int N = 1e5+5;
const double PI = acos(-1);
mt19937 rng(time(0));

int T;
LL n, k, l1, r1, l2, r2;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	
	cin>>T;
	while(T--){
		cin>>n>>k>>l1>>r1>>l2>>r2;
		if (l1>l2)
			swap(l1, l2), swap(r1, r2);
		
		if (r1 >= l2) {
			LL k1 = (min(r1,r2) - max(l1,l2)) * n, k2 = (max(r1,r2) - l1) * n;
			if (k <= k1) cout<<"0\n";
			else if (k <= k2) cout<<k-k1<<endl;
			else cout<<k2-k1+2ll*(k-k2)<<endl;
		}else{
			LL len = r2 - l1;
			if (k >= len * n) {
				cout<<(l2+r2-l1-r1)*n + (k - len * n) * 2ll<<endl;
			}else if(k < len){
				cout<<l2-r1+k<<endl;
			}else{
				LL x = k / len;
				k %= len;
				cout<<x * (l2+r2-l1-r1) + min(k*2, l2-r1+k)<<endl;
			}
		}
	}
	return 0;
}