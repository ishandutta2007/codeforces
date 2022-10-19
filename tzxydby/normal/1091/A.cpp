#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	cout<<3*(min(a+1,min(b,c-1)));
	return 0;
}