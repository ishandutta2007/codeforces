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
	map<char,char> m;
	m['>']='<',m['}']='{',m[']']='[',m[')']='(';
	string s;
	cin>>s;
	int ans=0;
	vector<char> v;
	for (int i=0;i<s.length();i++)
		if (m.count(s[i]))
		{
			if (!v.size()) return cout<<"Impossible",0;
			if (v.back()!=m[s[i]]) ans++;
			v.pop_back();
		}
		else v.push_back(s[i]);
	if (v.size()) cout<<"Impossible";
	else cout<<ans;
}