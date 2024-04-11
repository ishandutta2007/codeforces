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
int main()
{
	int n;
	cin>>n;
	vector<long long> v(n),sum(n+1),sum2(n+1);
	sum[0]=0;
	long long int ans=0;
	for(int i=0;i<n;i++) {cin>>v[i];sum[i+1]=sum[i]+v[i];sum2[i+1]=sum2[i]+v[i];}
	if(sum[n]%3!=0) {cout<<0;return 0;}
	long long c=sum[n]/3;
	long long int a=0;
	for(long long i=1;i<n;i++)
	{
		//cout<<ans;
		if(sum[i]==2*c) ans+=a;
		if(sum[i]==c) a+=1;
		//cout<<ans;
	}
	cout<<ans;
}