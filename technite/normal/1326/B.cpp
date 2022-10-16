#include<bits/stdc++.h>
using namespace std;
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
int main()
{
	long long n;
	cin>>n;
	long long a[n]={0},b[n];
	cin>>b[0];
	a[0]=b[0];
	long long maxi=b[0];
	for(int i=1;i<n;i++)
	{
		cin>>b[i];
		maxi=max(maxi,a[i-1]);
		a[i]=b[i]+maxi;

	}
	for(int i=0;i<n;i++) cout<<a[i]<<" ";

}