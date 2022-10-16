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
		cin>>n;
		if(n<=3)
		{
			cout<<-1<<"\n";
		}
		else
		{
			int cnt=0;
			if(n==4) cout<<"2 4 1 3\n";
			else
			{
				for(int i=1;i<=n;i+=2)
				{
					cout<<i<<" ";
					cnt++;
				}
			
			if(n%2)
			{
				cout<<n-3<<" "<<n-1<<" ";
				cnt+=2;
				for(int i=n-5;cnt<n;i=i-2)
				{
					cout<<i<<" ";
					cnt++;
				}
				cout<<"\n";
			}
			else
			{
				cout<<n-4<<" "<<n<<" "<<n-2<<" ";
				cnt+=3;
				for(int i=n-6;cnt<n;i=i-2)
				{
					cout<<i<<" ";
					cnt++;
				}
				cout<<"\n";

			}
		}
		}
	}	
}