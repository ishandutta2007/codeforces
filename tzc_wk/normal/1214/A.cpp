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
int n,d,e,ans=INT_MAX;
int lcm(int a,int b){
	return a*b/__gcd(a,b);
}
int main(){
	cin>>n>>d>>e;
	e*=5;
	for(int i=0;i<=n/d;i++){
		ans=min(ans,(n-i*d)%e);
	}
	cout<<ans<<endl;
	return 0;
}