#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s; 
		sort(s.begin(),s.end());
		string o,e;
		for(char c:s)
			(c%2?o:e)+=c;
		if(o.empty()||e.empty())
			cout<<o+e<<endl;
		else if(abs(o.back()-e[0])!=1)
			cout<<o+e<<endl;
		else if(abs(e.back()-o[0])!=1)
			cout<<e+o<<endl;
		else
			cout<<"No answer"<<endl;
	}
  return 0;
}