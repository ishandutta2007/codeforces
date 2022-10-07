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
const ll INF=1e11;
int n,a[N],maxx;
ll ans;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)cin>>a[i];
	for (int i=1;i<=n;i++)
	if (a[i]>maxx)maxx=a[i];
	for (int i=1;i<=n;i++)ans+=maxx-a[i];
	cout<<ans<<endl;
    return 0;
}