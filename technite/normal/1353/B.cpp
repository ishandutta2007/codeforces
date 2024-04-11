#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define F first
#define S second
#define append push_back
#define forn(i, n) for(int i = 0; i < n; ++i)
#define forl(i, n) for(long long i=0;i<n;++i)
typedef double dd;
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
void printvector(vector<ll>&v)
{
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<"\n";
}
int main(){
	int t;
	cin >> t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		vector<int> a(n),b(n);
		for(int i=0;i<n;i++) cin>>a[i];
		for(int i=0;i<n;i++) cin>>b[i];
		sort(a.begin(),a.end());
		sort(b.rbegin(),b.rend());
		for(int i=0;i<k;i++)
		{
			if(a[i]<b[i]) swap(a[i],b[i]);
			else break;
		}			
		long long ans=0;
		for(int i=0;i<n;i++) ans+=a[i];
		cout<<ans<<'\n';	
		
	}
}