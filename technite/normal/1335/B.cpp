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
int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		long long n,a,b;
		cin>>n>>a>>b;
		string s;
		for(long long i=0;i<n;i++) s+='0';
		long long coun=0;
		char c='a';
		for(int i=0;i<a;i++)
		{
			if(coun<b)
			{
				s[i]=c;
			}
			else
			{
				s[i]='a';
			}
			c++;
			coun++;
		}
		for(long long i=a;i<n;i++)
		{
			s[i]=s[i-a];
		}
		cout<<s<<"\n";
	}	
}