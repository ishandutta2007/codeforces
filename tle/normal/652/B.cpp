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
int n,a[23333],as[23333];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int cp=1;
	for(int i=1;i<=n;i++)
	{
		as[cp]=a[i];
		cp+=2; if(cp>n) cp=2;
	}for(int i=1;i<=n;i++) cout<<as[i]<<" ";
}