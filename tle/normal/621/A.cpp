#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <limits>
#include <set>
#include <map>
using namespace std;
int n,jn=0;
long long j[233333];
int main()
{
	long long ms=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long cur;
		cin>>cur;
		ms+=cur;
		if(cur%2==1) j[++jn]=cur;
	}
	sort(j+1,j+1+jn);
	if(jn%2==1) ms-=j[1];
	cout<<ms;
}