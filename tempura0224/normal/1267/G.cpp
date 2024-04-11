#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<n;++i)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)

using ld = long double;
long double dp[101][10001];
int main(){
	int n,x;
	cin>>n>>x;
	vector<int> a(n);
	rep(i,n){
		cin>>a[i];
	}
	dp[0][0]=1.0;
	rep(i,n){
		for(int j=n-1;j>=0;--j){
			rep(k,10001){
				if(k+a[i]<=10000)dp[j+1][k+a[i]]+=dp[j][k];
			}
		}
	}
	vector<ld> fact(n+1);
	fact[0]=1;
	rep(i,n)fact[i+1]=fact[i]*(i+1);
	ld ans = 0;
	Rep(j,1,n+1)rep(k,10001){
		ld prob = dp[j][k]*fact[j]*fact[n-j]/fact[n];
		ans += prob*min(0.5*(n+j)/j*x, 1.0*k/j);
	}
	cout<<fixed<<setprecision(12)<<ans<<endl;
}