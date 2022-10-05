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
int n,a[105],cnt1,cnt2;
int main(){
	cin>>n;
	REP(i,n)	cin>>a[i];
	REP(i,n){
		if(a[i]%2)	cnt1++;
		else		cnt2++;
	}
	cout<<min(cnt1,cnt2)<<endl;
	return 0;
}