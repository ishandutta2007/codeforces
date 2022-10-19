#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k,h;
	string s,w,v;
	cin>>n>>k>>s;
	h=INT_MAX;
	for(int i=1;i<(int)s.size();i++)
	{
		w=s.substr(i);
		v=s.substr(0,s.size()-i);
		if(w==v)
		{
			h=i;
			break;
		}
	}
	//cout<<h<<endl;
	if(h==INT_MAX)
	{
		while(k--)
			cout<<s;
	}
	else
	{
		cout<<s;
		k--;
		s=s.substr(s.size()-h);
		while(k--)
			cout<<s;
	}
	return 0;
}