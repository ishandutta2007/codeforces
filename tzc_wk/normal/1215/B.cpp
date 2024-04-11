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
int a[200005],n,sum[200005],ans1=0,ans2=0,cnt1=0,cnt2=0;
signed main(){
	cin>>n;
	REP(i,n)	cin>>a[i];
	REP(i,n){
		if(a[i]>0)	sum[i]=sum[i-1];
		else		sum[i]=sum[i-1]+1;
	}
	for(int i=0;i<=n;i++){
		if(sum[i]%2==1)	ans1+=cnt1,ans2+=cnt2;
		else			ans2+=cnt1,ans1+=cnt2;
		if(sum[i]%2==1)	cnt1++;
		else			cnt2++;
	}
	cout<<ans2<<" "<<ans1<<endl;
	return 0;
}