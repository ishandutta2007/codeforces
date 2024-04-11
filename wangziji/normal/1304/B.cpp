#include <iostream>
#include <map>
using namespace std;
map <string,int> mp;
inline bool pd(string a)
{
	for(int i=0;i<a.size();i++)
	{
		if(a[i]!=a[a.size()-i-1])
			return 0;
	}
	return 1;
}
inline string rev(string x)
{
	string a=x;
	for(int i=0;i<a.size()/2;i++)
		swap(a[i],a[a.size()-i-1]);
	return a;
}
string a[105];
int main(int argc, char** argv) {
	int n,m;
	string ans="";
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		++mp[a[i]];
		if(mp[rev(a[i])]>=1+pd(a[i]))
		{
			ans=a[i]+ans;
			ans=ans+rev(a[i]);
			mp[rev(a[i])]-=1,mp[a[i]]-=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(pd(a[i])&&mp[a[i]]>=1)
		{
			ans=ans.substr(0,ans.size()/2)+a[i]+ans.substr(ans.size()/2,ans.size()/2);
			break;
		}
	}
	cout << ans.size() << endl << ans;
	
	return 0;
}