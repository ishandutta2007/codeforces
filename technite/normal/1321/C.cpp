#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	long long n;
	cin>>n>>s;
	s="1"+s+"1";
	for (char i = 'z'; i >='a'; --i)
		for (int j = 0; j < s.size(); ++j)
			if (s[j]==i&&(s[j+1]==i-1||s[j-1]==i-1))
				s.erase(s.begin()+j),j=0;
	cout<<n-s.size()+2<<endl;
}