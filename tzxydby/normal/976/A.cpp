#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,s0,s1;
char s[N];
int main()
{
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='0')
			s0++;
		else
			s1++;
	}
	if(s1)
		printf("1");
	for(int i=1;i<=s0;i++)
		printf("0");
	return 0;
}