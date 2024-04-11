#include <bits/stdc++.h>
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
const int MOD=1e9+7,N=100005;
const int INF=1e8;
ll n,k,a[N];
ll M,ans,P;
int main()
{
	cin>>n>>k;
	for (int i=1;i<=n;i++)cin>>a[i];
	M=a[1];
	for (int i=2;i<=n;i++)M=MIN(M,a[i]);
	for (int i=1;i<=n;i++){
		if ((a[i]-M)%k)P=1;
		ans+=(a[i]-M)/k;
	}
	if (P)ans=-1;
	cout<<ans<<endl;
    return 0;
}