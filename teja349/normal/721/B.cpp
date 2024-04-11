#include <bits/stdc++.h>
using namespace std;
#include<string>
int main(){
	int n,k;
	cin>>n>>k;
	string a[110],s;
	int b[123]={0};
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
		b[a[i].length()]++;
	}
	cin>>s;
	int sum=0;
	int len=s.length();
	for (int i = 0; i < len; ++i)
	{
		sum+=b[i];
	}
	cout<<sum+(sum/k)*5+1<<" ";
	sum+=b[len]-1;
	cout<<sum+(sum/k)*5+1;
}