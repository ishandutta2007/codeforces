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
		int n;
		cin>>n;
		
		vector<int> v(n);
		cin>>v[0];
		bool b=true;
		for(int i=1;i<n;i++)
		{
			cin>>v[i];
			if(v[i]-v[i-1]>=2)
			{
				b=false;
			}

		}
		if(b) cout<<"YES";
		else cout<<"NO";
		cout<<"\n";
			


	}
}