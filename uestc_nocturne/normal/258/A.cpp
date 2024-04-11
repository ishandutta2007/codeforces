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
const int V=100100;
char s[V];
int main()
{
	while(~scanf("%s",s))
	{
		int n=strlen(s);
		bool find=false;
		for(int i=0;i<n-1;i++)
		if(find)printf("%c",s[i]);
		else if(s[i]=='1')printf("1");
		else {find=true;}
		if(find)printf("%c\n",s[n-1]);
	}
}