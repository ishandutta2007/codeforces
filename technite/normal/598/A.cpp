#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define F first
#define S second
#define append push_back
#define forn(i, n) for(int i = 0; i < n; ++i)
#define forl(i, n) for(long long i=0;i<n;++i)
#define endl "\n";
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
	fast;
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		long long p=(long long)log2(n);
		p++;
		long long a=(long long)n*((long long)n+1)/2;
		long long b=(long long)2*(((long long)1<<p)-(long long)1);
		cout<<a-b<<"\n";
	}	
}