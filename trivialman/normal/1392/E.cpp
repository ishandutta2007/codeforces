#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const int P = 1000000007;
const int INF = 1e9;
const int N = 30;
const double pi = acos(-1);
mt19937 rng(time(0));

int n, q;
LL x, a[N][N];

int main(){
	#ifndef ONLINE_JUDGE
	//freopen("test.in","r",stdin);
	#endif
	
	cin>>n;
	rep(j,2,n) a[n][j] = 1<<j-2;
	rrep(i,n-1,1) rep(j,2,n){
		x = n * 2 - i - j - 1;
		a[i][j] = a[i+1][j-1] + (1ll<<x);
	}
	
	rep(i,1,n) {
		rep(j,1,n)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
	cout<<flush;
	
	cin>>q;
	while(q--){
		cin>>x;
		LL res = 0;
		int i = 1, j = 1;
		cout<<i<<" "<<j<<endl;
		rrep(k,n*2-3,0){
			if(x>>k&1ll) j++;
			else i++;
			cout<<i<<" "<<j<<endl;
			res += a[i][j];
		}
		//cout<<"res = "<<res<<endl;
	}
	return 0;
}