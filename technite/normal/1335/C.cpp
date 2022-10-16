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
		int n;
		cin>>n;
		vector<int> v(n);
		set<int> s;
		map<int,int> m;
		for(int i=0;i<n;i++)
		{
			cin>>v[i];
			s.insert(v[i]);
			m[v[i]]++;
		}
		int mx=0;
		for(int i=0;i<n;i++)
		{
			mx=max(mx,m[v[i]]);
		}
		if(s.size()>mx) cout<<mx;
		else if(s.size()==mx) cout<<mx-1;
		else cout<<s.size();
		cout<<"\n";


	}	
}