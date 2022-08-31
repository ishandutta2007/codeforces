#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
long long xq(int a,int b)
{
	if(a<0) return 0;
	return a/b+1;
}
int main()
{
	int n,m;
	cin>>n>>m;
	long long p=0;
	for(int i=0;i<=4;i++)
	{
		int j=(5-i)%5;
		p+=max(xq(n-i,5)-(!i),0LL)*max(xq(m-j,5)-(!j),0LL);
	}
	cout<<p;
}