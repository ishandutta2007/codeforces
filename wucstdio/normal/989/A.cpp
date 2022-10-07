#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char c[105];
int n,a[105];
int main()
{
	scanf("%s",c);
	n=strlen(c);
	for(int i=1;i<n-1;i++)
	{
		if( (c[i]=='A'||c[i-1]=='A'||c[i+1]=='A')&&
			(c[i]=='B'||c[i-1]=='B'||c[i+1]=='B')&&
			(c[i]=='C'||c[i-1]=='C'||c[i+1]=='C'))
		{
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}