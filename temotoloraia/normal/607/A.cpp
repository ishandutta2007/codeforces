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
int n,ans,dp[N],ind,l,r,mid,x;
pair<int,int>P[N];
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)
	cin>>P[i].fr>>P[i].sc;
	sort(P+1,P+n+1);
	for (int i=1;i<=n;i++){
		x=P[i].fr-P[i].sc;
		ind=0;
		l=1;
		r=i-1;
		while (l<=r){
			mid=(l+r)/2;
			if (P[mid].fr<x){
				ind=mid;
				l=mid+1;
			}
			else {
				r=mid-1;
			}
		}
		dp[i]=dp[ind]+1;
	}
	ans=n-dp[1];
	for (int i=2;i<=n;i++)ans=min(ans,n-dp[i]);
	cout<<ans<<endl;
    return 0;
}