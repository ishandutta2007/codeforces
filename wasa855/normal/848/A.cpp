#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	if(n==0)
	{
		cout<<"abcdfghijk\n";
		return 0;
	}
	char tmp='a';
	while(n>0)
	{
		int sum=0;
		while(n>=sum)
		{
			cout<<tmp;
			n-=sum;
			sum++;
		}
		tmp++;
	}
	return 0;
}