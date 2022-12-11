#include <bits/stdc++.h>
using namespace std;
char s1[10],s2[10];
int n;
int main()
{
	scanf("%s%s",s1,s2);
	scanf("%d",&n);
	if (n%2==0) printf("undefined\n");
	else
	{
		if (n%4==1)
		{
			if (s1[0]=='v'&&s2[0]=='<') printf("cw\n"); else
			if (s1[0]=='<'&&s2[0]=='^') printf("cw\n"); else
			if (s1[0]=='^'&&s2[0]=='>') printf("cw\n"); else
			if (s1[0]=='>'&&s2[0]=='v') printf("cw\n");
			else printf("ccw\n");
		}
		if (n%4==3)
		{
			if (s1[0]=='v'&&s2[0]=='<') printf("ccw\n"); else
			if (s1[0]=='<'&&s2[0]=='^') printf("ccw\n"); else
			if (s1[0]=='^'&&s2[0]=='>') printf("ccw\n"); else
			if (s1[0]=='>'&&s2[0]=='v') printf("ccw\n");
			else printf("cw\n");
		} 
	}
	return 0;
}