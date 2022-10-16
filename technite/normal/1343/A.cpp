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
void printvector(vector<int>& v)
{
    for(auto x:v)
    {
        cout<<x<<" ";
    }
    cout<<"\n";
}

int main()
{
	
	long long t;
	cin >> t;
	while(t--)
	{
		long long a[(int)log2(1e10)];
		long long n;
		cin>>n;
		for(int i=2; pow(2,i)<1e9+1; i++)
		{
			a[i]=pow(2,i)-1;
			if(n%a[i]==0)
			{
				cout<<n/a[i]<<"\n";
				break;
			}
		}
	}
}