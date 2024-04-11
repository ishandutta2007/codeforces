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
const ll MOD=1e9+7,N=200001;
const ll INF=1e10;
ll n,a[N];
ll ind=INF,ans;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for (int i=1;i<n;i++)
	if (ind>a[i+1]-a[i])
	ind=a[i+1]-a[i];
	for (int i=1;i<n;i++)
	if (ind==a[i+1]-a[i])
	ans++;
	cout<<ind<<" "<<ans<<endl;
    return 0;
}