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
	long long t;
	cin>>t;
	while(t--)
	{
		long long n,x;
		cin>>n>>x;
		vector<long long> v;
		for(int i=0;i<n;i++)
		{
			long long a;
			cin>>a;
			v.push_back(a);
		}
		sort(v.begin(),v.end());
		reverse(v.begin(),v.end());
		long long sum=0,coun=0;
		for(int i=0;i<n;i++)
		{
			sum+=v[i];
			if(sum/(i+1)>=x)
			{
				coun++;
			}
			else break;
		}
		cout<<coun<<endl;
	}	
}