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
	int sum,d;
	cin>>d>>sum;
	vector<pair<int,int>> v;
	vector<int> ans(d);
	int mn=0,mx=0;
	for(int i=0;i<d;i++)
	{
		int a,b;
		cin>>a>>b;
		v.push_back({a,b});
		mn+=a;
		mx+=b;
		ans[i]=a;
	}
	if(mx<sum||mn>sum) {cout<<"NO";return 0;}
	cout<<"YES"<<endl;
	int diff=sum-mn;
	int i=0;
	while(diff>0)
	{
		if(diff<v[i].second-v[i].first) {ans[i]+=diff;diff=0;}
		else {ans[i]=v[i].second;diff=diff-(v[i].second-v[i].first);} 
		i++;
	}
	printvector(ans);

	
}