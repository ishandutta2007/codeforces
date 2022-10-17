#include<iostream>
#include<string>
using namespace std;
int a,t,u,i,j,n;
main()
{
	string s,p;
	cin>>s>>p;
	for(u=a=p.size(),t=s.size();i<u+t;i++,a=min(a,n))
		for(n=j=0;j<u;++j)
			n+=(i+j>=u&&i+j<u+t?s[i+j-u]!=p[j]:1);
	cout<<a;
}