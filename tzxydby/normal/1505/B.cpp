#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x;
	cin>>x;
	x%=9;
	if(x==0)
		x=9;
	cout<<x<<endl;
	return 0;
}