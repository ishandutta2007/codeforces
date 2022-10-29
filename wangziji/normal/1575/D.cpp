#include <bits/stdc++.h>
using namespace std;
string s;
inline bool check(int a)
{
	string t;
	while(a)
	{
		t+=a%10+'0';
		a/=10;
	}
	if(!t.size()) t+='0';
	reverse(t.begin(),t.end());
	int X=-1;
	if(t.size()!=s.size()) return 0;
	for(int i=0;i<t.size();i++)
	{
		if(s[i]=='_') continue;
		if(s[i]=='X')
		{
			if(X==-1) X=t[i];
			if(X!=t[i]) return 0;
		} 
		else if(s[i]!=t[i]) return 0;
	}
	return 1;
}
int main(int argc, char** argv) {
	cin >> s;
	int ans=0;
	for(int i=0;i<=100000000;i+=25) ans+=check(i);
	cout << ans;
	return 0;
}