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
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<int> v(n);
		for(int i=0; i<n; i++)
			cin >> v[i];
		int a=0,b=0; 
		int cnt=0;
		int i=0,j=n-1; 
		int la=0, lb=0;
		bool z=false;
		while(i<=j)
		{
			la=0;
			while(la<=lb)
			{
				a+=v[i];
				la+=v[i];
				i++;
				if(i>j)
				{
					z=true;
					break;
				}
			}
			cnt++;
			if(z)
				break;
			lb=0;
			while(lb<=la)
			{
				b+=v[j];
				lb+=v[j];
				j--;
				if(i>j)
				{
					z=true;
					break;
				}
			}
			cnt++;
			if(z)
				break;
		}
		cout<<cnt<<" "<<a<<" "<<b<<"\n";
	}
}