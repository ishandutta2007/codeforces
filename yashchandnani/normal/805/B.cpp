#include <bits/stdc++.h>
using namespace std;

int main(){

	long long int n;
	cin>>n;
	long long int x= n/4;
	int y = n%4;
	for (int i = 0; i < x; ++i)
	{
		cout<<"aabb";
	}
	if (y==1)
	{
		cout<<"a";
	}
	else if (y==2)
	{
		cout<<"aa";
	}
	else if (y==3)
	{
		cout<<"aab";
	}
	


	return 0;
}