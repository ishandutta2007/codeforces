#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	int n=0;

	for (int i = 0; i < s.size()/2; ++i)
	{
		if (s[i]!=s[s.size()-1-i])
		{
			n++;
		}
	}
	if (n>1)
	{
		cout<<"NO";
	}
	else{
		if ((n!=1)&&(s.size()%2==0))
		{
			cout<<"NO";
		}
		else{
			cout<<"YES";
		}
	}
	return 0;
}