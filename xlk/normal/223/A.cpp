#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cctype>
#include<algorithm>
#include<vector>
#include<queue>
#include<iostream>
#include<set>
#include<map>
using namespace std;
char s[100010];
int a[100010][2],l;
int main()
{
	scanf("%s",s);
	l=strlen(s);
	for(int i=l-1;i--;)
	{
		int A=0,B=0,C=0;
		if(s[i]!='('&&s[i]!='[')
			continue;
		if(s[i]=='(')
			A++;
		else
			B++,C++;
		for(int j=i+1;j!=l;)
		{
			if(s[j]=='('||s[j]=='[')
			{
				if(!a[j][0])
					break;
				C+=a[j][1];
				j+=a[j][0];
			}
			else if(s[j]==')')
			{
				if(A)
					A--,j++;
				else
					break;
			}
			else if(s[j]==']')
			{
				if(B)
					B--,j++;
				else
					break;
			}
			if(A==0&&B==0)
			{
				a[i][0]=j-i;
				a[i][1]=C;
			}
		}
	}
	int ans=0;
	for(int i=0;++i!=l;)
	{
		if(a[ans][1]<a[i][1])
			ans=i;
	}
	printf("%d\n",a[ans][1]);
	for(int i=-1;++i!=a[ans][0];)
	{
		putchar(s[ans+i]);
	}
	return 0;
}