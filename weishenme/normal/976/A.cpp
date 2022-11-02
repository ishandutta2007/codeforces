#include<bits/stdc++.h>
using namespace std;
int n;
char s[105];
int main()
{
	scanf("%d",&n);
	scanf("%s",&s);
	int x=0,y=0;
	for (int i=0;i<n;i++)
	 if (s[i]=='0')x++;
	 else y++;
	if (y==0)
	 {
	 	puts("0");
	 	return 0;
	 }
	printf("1");
	for (int i=1;i<=x;i++)putchar('0'); 
}