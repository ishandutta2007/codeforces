#include<bits/stdc++.h>
using namespace std;
vector<int>s;
int n,k,a,p;
int main()
{
	cin>>n>>k;
	for(int x=1;x<=n;x++)
		s.push_back(x);
	while(k--)
	{
		cin>>a;
		p=(p+a)%s.size();
		cout<<s[p]<<" ";
		s.erase(s.begin()+p);
	}
	return 0;
}