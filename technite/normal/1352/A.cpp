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

int32_t main()
{
	fast;
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		vector<string> ans;
		int n = s.size();
		for(int i = 0; i < n; i++)
		{
			if(s[i] > '0')
			{
				string cur = "";
				cur += s[i];
				for(int j = i + 1; j < n; j++)
					cur += '0';
				ans.push_back(cur);
			}
		}
		cout << ans.size() << endl;
		for(auto &it:ans)
			cout << it << " ";
		cout << endl;
	}
	return 0;
}