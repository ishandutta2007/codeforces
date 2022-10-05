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
int n,l,r,cur=1,mn,mx;
signed main(){
	cin>>n>>l>>r;
	for(int i=1;i<=min(r,n);i++){
		mx+=cur;
		cur*=2;
	}
	cur/=2;
	for(int i=min(r,n)+1;i<=n;i++)	mx+=cur;
	cur=1;
	for(int i=1;i<=min(l,n);i++){
		mn+=cur;
		cur*=2;
	}
	for(int i=min(l,n)+1;i<=n;i++)	mn++;
	cout<<mn<<" "<<mx<<endl;
	return 0;
}