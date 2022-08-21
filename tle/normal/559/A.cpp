#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
int a1,a2,a3,a4,a5,a6;
int main()
{
	scanf("%d%d%d%d%d%d",&a1,&a2,&a3,&a4,&a5,&a6);
	int b1=a6*a6,b2=a2*a2,b3=a4*a4;
	printf("%d",(a6+a1+a2)*(a6+a1+a2)-b1-b2-b3);
}