#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long a,b,c;
	cin>>a>>b>>c;
	cout<<c*2+min(a,b)+min(min(a,b)+1,max(a,b))<<endl;
	return 0;
}