#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define rrep(i,a,b) for(int i=(a);i>=(b);i--)
#define PB push_back
typedef long long LL;
const int P = 998244353;
const int N = 100005;

int T, n, a[N];
vector<int> dp, dp1, num, num1;

int main(){
	//freopen("in.txt","r",stdin);
	cin>>T;
	while(T--){
		scanf("%d",&n);
		rep(i,1,n) scanf("%d",a+i);
		int ans = 0;
		rrep(i,n,1) {
			int x = a[i], q = sqrt(x-1);
			num.resize(2*q+1), dp.resize(2*q+1);
			rep(j,0,2*q) dp[j] = 0;
			rep(j,1,q+1) num[j-1] = j;
			int tot = (q>0&&(x-1)/q+1==q+1)?q*2:q*2+1;
			if (tot==q*2) dp.pop_back(), num.pop_back();
			rep(j,1,q) num[tot-j] = (x-1)/j+1;
			
			dp[tot-1] = 1;
			if (i<n) {
				int j1 = 0;
				rep(j,0,tot-1) {
					while(j1<dp1.size() && (j==tot-1 || num1[j1]-(a[i+1]%num1[j1]>0)<num[j+1]))
						dp[j] += dp1[j1], j1++;
				}
				rep(j,0,tot-1) ans = (ans + 1ll * dp[j] * i * ((a[i]-1)/num[j])) % P;
			}
			dp1 = dp, num1 = num;
		}
		printf("%d\n", ans);
	}
}