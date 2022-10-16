#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define F first
#define S second
#define pb push_back
#define mp make_pair
typedef long long ll;
ll exp(ll n, ll m, ll md){
    ll a = 1;
    while (m > 0){
        if (m&1) a = (a * n%md) % md;
        m /= 2;
        n = (n*n) % md;
    }
    return a % md;
}
void printvector(vector<int> v)
{
	for (int i=0;i<v.size();i++)
		cout<<v[i]<<" ";
	cout<<"\n";
}
int main()
{
	fast;
	int t;
	cin>>t;
	while(t--)
	{
		long long a,b,q;
		cin>>a>>b>>q;
		long long lcm=a*b/__gcd(a,b);
		if(a>b) swap(a,b);
		while(q--)
		{
			ll l,r,ans=0;
			cin>>l>>r;
			ll x1=((l-1)/lcm)*(lcm-b);
			ll f=(l-1)%lcm;
			x1+=max((ll)0,f-b+1);
 
			ll x2=((r)/lcm)*(lcm-b);
			f=(r)%lcm;
			x2+=max(0ll,f-b+1);
			ans=x2-x1;

			cout<<ans<<" ";
		}
		cout<<"\n";
	}
}