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
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int h=1,rem=n-1;
		vector<int> ans;
		while(rem >= 0)
		{
			if(h*2>=rem)
			{
				ans.push_back(rem - h);
				break;
			}
			int x = min(rem/2-h,h);
			ans.push_back(x);
			h += x;
			rem -= h;
		}
		cout<<ans.size()<<endl;
		for(auto it:ans)
			cout<<it<<" ";
		cout<<"\n";
	}
}