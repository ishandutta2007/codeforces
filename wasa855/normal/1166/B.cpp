#include<bits/stdc++.h>
using namespace std;
string a="aeiou";
void print(int x,int y)
{
	for(int i=1;i<=x;i++)
	{
		for(int j=1;j<=y;j++)
		{
			cout<<a[(i+j)%5];
		}
	}
}
int main()
{
	int n;
	cin>>n;
	for(int i=5;i*i<=n;i++)
	{
		if(n%i==0&&n/i>=5)
		{
			print(i,n/i);
			return 0;
		}
	}
	cout<<"-1\n";
	return 0;
}