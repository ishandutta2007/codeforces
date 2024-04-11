#include <bits/stdc++.h>
using namespace std;
string s;
bool check;
int main()
{
	cin>>s;
	int cnt=0;
	check=false;
	for (int i=0;i<s.length()/2;i++)
		if (s[i]!=s[s.length()-i-1]) ++cnt;
	if ((cnt==1)||(cnt==0&&s.length()%2==1)) cout << "YES"<<endl; else cout << "NO"<<endl;
	return 0;
}