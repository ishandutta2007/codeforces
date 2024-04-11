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
const int MOD=1e9+7,N=5e5+5;
const ll INF=1e18;
ll n,m,k,l,r,mid,ans=1;
ll a,b,c,d,sum;
ll f (ll start, ll end)
{
	if (start>end)return 0;
	return (start+end)*(end-start+1)/2;
}
int main(){
	cin>>n>>m>>k;
	l=1;
	r=m;
	while (l<=r){
		// n=3 k=3 mid=4
		mid=(l+r)/2;
		sum=mid;
		if (mid>=k){
			sum+=f(mid-k+1,mid-1);
		}
		else {
			sum+=f(1,mid-1)+k-mid;
		}
		if (n-k+1>=mid){
			sum+=f(1,mid-1)+n-k+1-mid;
		}
		else {
			sum+=f(mid-(n-k),mid-1);
			//if (mid==4)cout<<mid-(n-k)<<" "<<mid-1<<endl;
		}
		if (sum<=m){
			ans=mid;
			l=mid+1;
		}
		else {
			r=mid-1;
			//cout<<mid<<" "<<sum<<endl;
		}
	}
	cout<<ans<<endl;
    return 0;
}