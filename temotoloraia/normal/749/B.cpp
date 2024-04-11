#include <bits/stdc++.h>
using namespace std;
int a,b,c,d,e,f;
main()
{
	cin>>a>>b>>c>>d>>e>>f;
	cout<<3<<endl;
	cout<<e+c-a<<" "<<f+d-b<<endl;
	cout<<e+a-c<<" "<<f+b-d<<endl;
	cout<<a+c-e<<" "<<b+d-f<<endl;
}