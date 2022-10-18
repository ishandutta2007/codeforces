#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a;
	cin>>a;
	int n=a.length();
	stack<char> s;
	s.push(a[n-1]);
	for(int i=n-2;i>=0;i--)
	{
		if(a[i]>=s.top())
		{
			s.push(a[i]);
		}
	}
	while(!s.empty())
	{
		printf("%c",s.top());
		s.pop();
	}
	cout<<"\n";
	return 0;
}