#include <bits/stdc++.h>
#define int long long
using namespace std;
string s;
char p[10]="abc";
signed main(int argc, char** argv) {
	int n;
	cin >> n;
	string a,b;
	cin >> a >> b;
	int flag=1;
	if(a[0]==a[1]||b[0]==b[1])
	{
	do
	{
		s="";
		for(int i=1;i<=n;i++)
			s+=p[0],s+=p[1],s+=p[2];
		int flag=1;
		for(int i=1;i<s.size();i++)
		{
			if(s[i]==a[1]&&s[i-1]==a[0])
				flag=0;
			if(s[i]==b[1]&&s[i-1]==b[0])
				flag=0;
		}
		if(flag)
		{
			cout <<"YES\n";
			cout << s;
			return 0;
		}
	}
	while(next_permutation(p,p+3));
	cout << "NO";
	return 0;
	}
	
	do
	{
		s="";
		for(int i=1;i<=1;i++)
			s+=p[0],s+=p[1],s+=p[2];
		int flag=1;
		for(int i=1;i<s.size();i++)
		{
			if(s[i]==a[1]&&s[i-1]==a[0])
				flag=0;
			if(s[i]==b[1]&&s[i-1]==b[0])
				flag=0;
		}
		if(flag)
		{
			cout <<"YES\n";
			for(int i=1;i<=n;i++)cout << s[0];
			for(int i=1;i<=n;i++)cout << s[1];
			for(int i=1;i<=n;i++)cout << s[2];
			return 0;
		}
	}
	while(next_permutation(p,p+3));
	cout << "NO";
	return 0;
	return 0;
}