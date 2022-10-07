#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int num[26],n;
char s[100005];
int main()
{
	scanf("%d%s",&n,s);
	for(int i=0;i<n;i++)
	  num[s[i]-'a']++;
	for(int i=0;i<26;i++)
	{
		for(int j=1;j<=num[i];j++)
		  putchar(i+'a');
	}
	printf("\n");
	return 0;
}