#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const int N = 1e5+5;
mt19937 rng(time(0));

int T;
LL n, k;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	cin>>T;
	while(T--){
		cin>>n>>k;
		k = n*(n-1)/2+1-k;
		LL th = 0, i = 1, j;
		while(th<k && i<n){
			th += n-i;
			i++;
		}
		i--; th -= (n-i);
		j = k - th + i;
		
		rep(x,1,n) printf(x==i||x==j ? "b" : "a");
		cout<<endl;
	}
	return 0;
}