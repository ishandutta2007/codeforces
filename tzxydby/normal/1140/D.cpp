#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	long long sum=0;
	cin>>n;
	for(int i=2;i<n;i++)
		sum+=i*(i+1);
	cout<<sum<<endl;
	return 0;
}