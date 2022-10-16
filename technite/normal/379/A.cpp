#include<iostream>
#include<cstring>
#include<string>
#include<bits//stdc++.h>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	int i=a;
	int sum=0;
	int used=a*b;
	while(used>=b){
	i=used/b;
	used=used%b;	
	
	while(i>0)
	{
		sum=sum+i;
		used=used+i%b;
		i=i/b;
	}
}
	cout<<sum;
}