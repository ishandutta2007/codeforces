#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,flag=0;
	cin>>n;
	int a[n],b[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i]>>b[i];
		if (a[i]!=b[i])
		{
			cout<<"rated"<<endl;
			return 0;
		}
		if ((a[i]>a[i-1])&&(i!=0))
		{
			flag=1;
		}
	}
	if (flag)
	{
		cout<<"unrated"<<endl;
	}
	else{
		cout<<"maybe"<<endl;
	}
	return 0;
}