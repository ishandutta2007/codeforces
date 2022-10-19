#include<bits/stdc++.h>
using namespace std;
int main()
{
	string x;
	cin>>x;
	vector<int>v;
	for(auto c:x)
		v.push_back(c-'A');
	for(int i=0;i+2<v.size();i++)
	{
		if((v[i]+v[i+1])%26!=v[i+2])
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}