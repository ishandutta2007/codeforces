#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int,2>
typedef long long LL;
const LL P = 1e9+7;
const LL INF = 1e18;
const int N = 1e5+5;
mt19937 rng(time(0));
 
int T, n, x;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	
	cin>>T;
	while(T--){
		cin>>n;
		rep(i,1,n){
			cin>>x;
			int sign = i%2==1 ? 1 : -1;
			cout<<sign*abs(x)<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}