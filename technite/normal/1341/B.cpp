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
void printvector(vector<ll> v)
{
	for (auto x : v)
		cout<<x<<" ";
	cout<<"\n";
}
int main()
{
	fast;
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		vector<int> v(n),peak(n);
		for(int i=0;i<n;i++) cin>>v[i];
		for(int i=1;i<n-1;i++)
		{
			if(v[i]>v[i-1]&&v[i]>v[i+1]) peak[i]=1;
		}	
		int l=0;
		int len=0;
		int coun=0;
		int ans=0;
		int i=0,j=1;
		for(int j=1;j<n;j++)
		{
			if(j-i+1==k)
			{
				if(coun>ans)
				{
					l=i;
					ans=coun;
					
				}
				i++;
				if(peak[i]==1) coun--;
			}
			if(peak[j])coun++;
			
		}	
		cout<<ans+1<<" "<<l+1<<"\n";

	}
}