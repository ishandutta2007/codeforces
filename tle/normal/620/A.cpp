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
int main()
{
	int x1,y1,x2,y2;
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	int x=x2-x1,y=y2-y1;
	if(x<0) x=-x;
	if(y<0) y=-y;
	if(x>y) swap(x,y);
	printf("%d\n",y);
}