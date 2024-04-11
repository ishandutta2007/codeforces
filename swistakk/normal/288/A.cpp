#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <utility>
#include <ctime>
#include <cstdio>
#define uint long long int
#define N 1000005
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	int n, k;
	cin>>n>>k;
	if(k>n)
	{
		cout<<"-1"<<endl;
		return 0;
	}
	int wol=n-k;
	int licz=0;
	if(n==1)
	{
		cout<<"a"<<endl;
		return 0;
	}
	if(k==1)
	{
		cout<<"-1"<<endl;
		return 0;
	}
	if(n==2)
	{
		cout<<"ab"<<endl;
		return 0;
	}
	cout<<"ab";
	while(wol)
	{
		if(licz==0)
		{
			cout<<"a";
		}
		else
		{
			cout<<"b";
		}
		wol--;
		licz^=1;
	}
	for(int i=1; i<=k-2; i++)
	{
		cout<<char(int('a')+i+1);
	}
	cout<<endl;
	
	return 0;
}