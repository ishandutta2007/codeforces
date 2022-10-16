#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define F first
#define S second
#define append push_back
#define forn(i, n) for(int i = 0; i < n; ++i)
#define forl(i, n) for(long long i=0;i<n;++i)
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
void printarray(int a[], int n)
{
	for (int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<"\n";
}
void printvector(vector<int> v)
{
	for (auto x : v)
		cout<<x<<" ";
	cout<<"\n";
}
int main()
{
	fast;
	long long t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int cnt=0;
		while(n>=2) 
		{
        	long long i = 0;
        	while((3*(i+1)-1)<=n) 
        	{
            	i++;
            	n-=(3*i-1);
        	}
        cnt++;
    }
    cout<<cnt<<"\n";

	}	
}