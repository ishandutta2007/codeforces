#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <set>
using namespace std;
int n,a[233333];
multiset<int> ms;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i), ms.insert(a[i]);
	for(int i=1;;i++)
	{
		multiset<int>::iterator p=ms.lower_bound(i);
		if(p==ms.end()) {printf("%d\n",i); return 0;}
		ms.erase(p);
	}
}