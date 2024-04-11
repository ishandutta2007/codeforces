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
int T,n,a[150005];
inline void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>a[i];
	int mn=INT_MAX,cnt=0;
	for(int i=n;i>=1;i--){
		if(a[i]<=mn)	mn=a[i];
		else			cnt++;
	}
	cout<<cnt<<endl;
}
int main(){
	cin>>T;
	while(T--)	solve();
	return 0;
}