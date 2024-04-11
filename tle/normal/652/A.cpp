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
long long h1,h2,a,b;
int main()
{
	cin>>h1>>h2>>a>>b;
	for(int d=0,h=15;d<=6000000;++h,(h==24)?(h=0,d++):0)
	{
		if(11<=h&&h<=22) h1+=a;
		else h1-=b;
		if(h1<=-100000000000000LL) break;
		if(h1>=h2) {printf("%d\n",d); return 0;}
	}
	printf("-1\n");
}