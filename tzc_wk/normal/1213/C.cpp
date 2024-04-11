#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define MOD			1000000007
#define FOR(i,l,r)	for(int i=l;i<=r;i++)
#define REP(i,n)	for(int i=1;i<=n;i++)
#define REP0(i,n)	for(int i=0;i<n;i++)
#define PB			push_back
#define MP			make_pair
#define PII			pair<int,int>
#define VI			vector<int>
#define ALL(x)		(x).begin(),(x).end()
#define int long long
int T,n,m;
inline int lcm(int a,int b){
	return a*b/__gcd(a,b);
}
inline void solve(){
	cin>>n>>m;
	int x=lcm(m,10);
	int sum=0;
	for(int i=1;i<=x/m;i++)	sum+=(i*m)%10;
	int ans=0;
	ans+=(n/x)*sum;
	n%=x;
	for(int i=1;i<=n/m;i++)	ans+=(i*m)%10;
	cout<<ans<<endl;
}
signed main(){
	cin>>T;
	while(T--)	solve();
	return 0;
}