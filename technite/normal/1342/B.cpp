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
	fast;
	int t;
	cin>>t;
	for (int i1=0;i1<t;i1++)
	{
		string s;
		cin>>s;
		char a = s[0];
		bool ans = true;
		for (int i=1;i<s.length();i++)
		{
			if (s[i] != a)
			{
				ans = false;
				break;
			}
		}
		if (ans)
			cout<<s<<"\n";
		else
		{
			for (int i=0;i<s.length();i++)
				cout<<"10";
			cout<<"\n";
		}
	}
}