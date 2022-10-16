#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define F first
#define S second
#define pb push_back
#define mp make_pair
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
void printvector(vector<int> v)
{
	for (int i=0;i<v.size();i++)
		cout<<v[i]<<" ";
	cout<<"\n";
}
int main()
{
	int n,k;
	cin>>n>>k;
	vector<int> v(n),c(k+1),size(k+1);
	for(int i=0;i<n;i++) cin>>v[i];
	for(int i=1;i<=k;i++) cin>>c[i];
	sort(v.begin(),v.end());	
	for(int i=0;i<n;i++)
	{
		size[v[i]]++;
	}
	int ans=ceil(size[k]/c[k]);
	for(int i=k-1;i>=1;i--)
	{
		size[i]=size[i+1]+size[i];
		//cout<<size[i]<<" ";
		int x=size[i]/c[i];
		if(size[i]%c[i]!=0) x++;
		//cout<<x<<" ";
		ans=max(ans,x);
	}
	//cout<<"\n";
	cout<<ans<<"\n";
	vector<int> a[ans];
	for(int i=0;i<n;i++)
	{
		a[i%(ans)].pb(v[i]);
	}
	for(int i=0;i<ans;i++)
	{
		cout<<a[i].size()<<" ";
		for(int j=0;j<a[i].size();j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	

		
}