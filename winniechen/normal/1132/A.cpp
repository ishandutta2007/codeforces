#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define ll long long
int s1,s2,s3,s4;
int main()
{
	scanf("%d%d%d%d",&s1,&s2,&s3,&s4);
	if(!s1)
	{
		if(s3+s4)return puts("0"),0;
		return puts("1"),0;
	}
	if(s1==s4)return puts("1"),0;
	puts("0");
}