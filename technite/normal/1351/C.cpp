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
	int n;
	cin>>n;
	map<pair<float,float>,int> m;
	while (n--)
	{
		string s;
		cin>>s;
		m.clear();
		int x=0,y=0,cnt=0;
		for (auto a: s)
		{
			if (a=='N')
			{
				if (m[{x,y+0.5}]) cnt+=1;
				else cnt+=5,m[{x,y+0.5}]=1;
				++y;
			}
			if (a=='S')
			{
				if (m[{x,y-0.5}]) cnt+=1;
				else cnt+=5,m[{x,y-0.5}]=1;
				--y;
			}
			if (a=='E')
			{
				if (m[{x+0.5,y}]) cnt+=1;
				else cnt+=5,m[{x+0.5,y}]=1;
				++x;
			}
			if (a=='W')
			{
				if (m[{x-0.5,y}]) cnt+=1;
				else cnt+=5,m[{x-0.5,y}]=1;
				--x;
			}
		}
		cout<<cnt<<endl;
	}
}