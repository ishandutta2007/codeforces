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
int T,a,b,n;
inline void solve(){
	cin>>a>>b>>n;
	int ans=0;
	for(int i=30;i>=0;i--){
		int dig1=(a>>i)&1,dig2=(b>>i)&1;
		if(dig1==1&&dig2==0){
			if(n%3!=1)	ans|=(1<<i);
		}
		else if(dig1==0&&dig2==1){
			if(n%3)		ans|=(1<<i);
		}
		else if(dig1&&dig2){
			if(n%3!=2)	ans|=(1<<i);
		}
	}
	cout<<ans<<endl;
}
int main(){
	cin>>T;
	while(T--)	solve();
	return 0;
}