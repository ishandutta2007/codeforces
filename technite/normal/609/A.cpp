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
	

		int n,m;
		cin>>n>>m;
		vector<int> v(n);
		for(int i=0;i<n;i++) cin>>v[i];
		sort(v.begin(),v.end());
		int coun=0;
		int sum=0;
		for(int i=n-1;i>=0;i--)
		{
			sum+=v[i];
			coun++;
			if(sum>=m)
			{
				cout<<coun<<"\n";
				return 0;

			}
		}
	
}