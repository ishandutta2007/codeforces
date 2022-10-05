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
int n,a[200005],cnt=0;
signed main(){
	cin>>n;
	if(n%2==0)	return puts("NO"),0;
	puts("YES");
	for(int i=n,j=2*n,k=2*n;i>0;){
		a[i]=k;
		a[j]=k-1;
		if(i-1>0){
			a[j-1]=k-2;
			a[i-1]=k-3;
		}
		i-=2;
		j-=2;
		k-=4;
	}
	for(int i=1;i<=2*n;i++)	cout<<a[i]<<" ";
	return 0;
}