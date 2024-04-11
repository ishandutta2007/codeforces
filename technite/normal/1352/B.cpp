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
	int  t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		bool ans=false;
		if(n%2==0)
		{
			if(n>=2*k)
			{
				cout<<"YES"<<"\n";
				for(int i=0;i<k-1;i++)
				{
					cout<<2<<" ";
				}
				cout<<n-(k-1)*2;
				ans=true;
			}
			else if(n>=k&&k%2==0)
			{
				cout<<"YES"<<"\n";
				ans=true;
				for(int i=0;i<k-1;i++)
				{
					cout<<1<<" ";
				}
				cout<<n-(k-1);
			}

		}
		else
		{
			if(k%2==1&&n>=k)
			{
				ans=true;
				cout<<"YES"<<"\n";
				for(int i=0;i<k-1;i++)
				{
					cout<<1<<" ";
				}
				cout<<n-(k-1);
			}
		}
		if(!ans) cout<<"NO";
		cout<<"\n";
	}

}