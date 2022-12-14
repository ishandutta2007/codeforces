#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e6 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;

int main()
{
	ll a[3],d,ans=0,dis1,dis2;
	for(int i=0;i<3;i++)cin>>a[i];
	cin>>d;
	sort(a,a+3);
	dis1=a[1]-a[0],dis2=a[2]-a[1];

	if(dis1<d)ans+=d-dis1;
	if(dis2<d)ans+=d-dis2;

	cout<<ans;
	return 0;
}