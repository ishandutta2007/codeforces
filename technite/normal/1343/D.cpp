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
void printvector(vector<int>& v)
{
    for(auto x:v)
    {
        cout<<x<<" ";
    }
    cout<<"\n";
}
int main()
{
    
    int t;
	cin>>t;
	for (int i1=0;i1<t;i1++)
	{
		int n, k;
		cin>>n>>k;
		vector<int> v(n), sum(2 * k + 1),v1,v2;
		for (int i=0;i<n;i++)
			cin>>v[i];
		for (int i=0;i<n/2;i++)
			sum[v[i] + v[n - i - 1]]++;
		for (int i=0;i<n/2;i++)
		{
			v1.push_back(1 + min(v[i], v[n-i-1]));
			v2.push_back(k + max(v[i], v[n-i-1]));
		}
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		int crr = n;
		for (int i=2;i<2*k + 1;i++)
		{
			auto it1 = upper_bound(v1.begin(), v1.end(), i);
			auto it2 = lower_bound(v2.begin(), v2.end(), i);
			int a1 = (it1 - v1.begin());
			int a2 = (it2 - v2.begin());
			crr = min(crr, n - (a1 - a2) - sum[i]);
		}
		cout<<crr<<"\n";
	}
}