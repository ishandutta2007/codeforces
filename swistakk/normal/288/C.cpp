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
int per[N];
int main()
{
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	for(int i=0; i<=n; i++)
	{
		per[i]=i;
	}
	int pot=1;
	while(pot<=n)
	{
		for(int i=0; i<=n-pot; i++)
		{
			if((pot&i)==0)
			{
				swap(per[i], per[i+pot]);
			}
		}
		pot*=2;
	}
	uint wynik=0;
	for(int i=0; i<=n; i++)
	{
		wynik+=(i^per[i]);
	}
	cout<<wynik<<endl;
	for(int i=0; i<=n; i++)
	{
		cout<<per[i]<<" ";
	}
	cout<<endl;
	
	
	
	return 0;
}