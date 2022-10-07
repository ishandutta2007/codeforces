#include <bits/stdc++.h>
#define ll long long
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
using namespace std;
const int MOD=1e9+7,N=1e5+5;
const ll INF=1e17;
ll st,en,t,n,a[N],dp[N],pas,ind=-1;
int main(){
	cin>>st>>en>>t>>n;
	for (int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	dp[1]=max(a[1],st)+t-1;
	for (int i=2;i<=n;i++)dp[i]=max(dp[i-1]+t,a[i]+t-1);
	if (dp[n]<=en-t){
		cout<<en-t<<endl;
		return 0;
	}
	for (int i=1;i<n;i++)
	if (dp[i]+1<a[i+1]&&dp[i]+1+t<=en){
		cout<<dp[i]+1<<endl;
		return 0;
	}
	if (a[1]>=en){cout<<st<<endl;return 0;}
	if (a[1]>0&&a[1]-1<=en-t){
		ind=a[1]-1;
		pas=st-(a[1]-1);
	}
	for (int i=2;i<=n;i++)
	if (dp[i-1]<=en-t&&a[i]>0){
		if (ind==-1||pas>dp[i-1]-(a[i]-1)+1){
			ind=a[i]-1;
			pas=dp[i-1]-(a[i]-1)+1;
		}
	}
	cout<<ind<<endl;
    return 0;
}