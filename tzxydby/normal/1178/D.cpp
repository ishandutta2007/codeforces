#include<bits/stdc++.h>
using namespace std;
const int N=1005;
vector<pair<int,int>>a;
int is_p(int x)
{
	int i;
	for(i=2;i*i<x;i++)
		if(x%i==0)
			return 0;
	if(i*i==x)
		return 0;
	return 1;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
		a.emplace_back(i,i+1);
	a.emplace_back(n,1);
	int t=n,k=1;
	while(!is_p(t))
	{
		t++;
		a.emplace_back(k,k+2);
		k++;
		if(k%4==3)
			k+=2;
	}
	printf("%d\n",a.size());
	for(auto i:a)
		printf("%d %d\n",i.first,i.second);
	return 0;
}