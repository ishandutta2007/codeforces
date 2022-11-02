/*
Author: elfness@UESTC
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
int main()
{
	printf("%d\n",302);
	printf("0 1000000\n");
	int pos=40*1000;
	for(int i=0;i<300;i++)
	{
		printf("%d %d\n",pos,302-i);
		pos+=604;
	}
	printf("1000000 1000000\n");
}