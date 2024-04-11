#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int n,c=0;
bool cell[100001];
int main()
{
	scanf("%d\n",&n);
	for(int i=1;i<=n;i++) cell[i]=getchar()-'0';
	cell[1]=!cell[1];
	for(int i=1;i<=n;i++)
	{
		c++;
		if(!cell[i]) cell[i+1]=!cell[i+1]; else break;
	} 
	printf("%d",c);
	return 0;
}