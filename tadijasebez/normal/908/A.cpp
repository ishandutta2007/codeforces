#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int min(int a, int b){ return a>b?b:a;}
int max(int a, int b){ return a>b?a:b;}
char ch[100];
int main()
{
	int n,i,sol=0;
	scanf("%s",&ch);
	n=strlen(ch);
	for(i=0;i<n;i++)
	{
		if(ch[i]=='a' || ch[i]=='e' || ch[i]=='i' || ch[i]=='o' || ch[i]=='u') sol++;
		if(ch[i]>'0' && ch[i]<='9')
		{
			int tmp=ch[i]-'0';
			if(tmp%2==1) sol++;
		}
	}
	printf("%i\n",sol);
	return 0;
}