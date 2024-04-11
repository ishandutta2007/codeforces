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
	string s;
	cin>>s;
	int m;
	cin>>m;
	for(int i=0;i<m;i++)
	{
		int l,r,k;
		cin>>l>>r>>k;
		string a=s.substr(l-1,r-l+1);
		for(int j=0;j<a.size();j++)
		{   
		    s[(j+k)%a.size()+l-1]=a[j];
		} 	
	}
	cout<<s;
}