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
const int MOD=1e9+7,N=1e6+5;
const ll INF=1e17;
int n,a[N],st,en;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if (a[n]==a[1]){
		cout<<0<<endl;
		return 0;
	}
	st=n;en=1;
	for (int i=2;i<=n;i++)
	if (a[i]>a[i-1]){
		st=i;
		break;
	}
	for (int i=n-1;i>=1;i--)
	if (a[i]<a[i+1]){
		en=i;
		break;
	}
	if (st>en){cout<<0<<endl;return 0;}
	cout<<en-st+1<<endl;
    return 0;
}