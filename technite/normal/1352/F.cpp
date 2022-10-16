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
		int a,b,c;
		cin>>a>>b>>c;
		string x(a+1,'0'),y(c+1,'1'),z="";
		int cnt=1;
		if(b==0){
			if(a==0)
				x="";
			if(c==0)
				y="";
		}
 
		while(cnt++<b)
			z+=(cnt%2)?'1':'0';
 
		cout<<x<<y<<z<<endl;
	}	
}