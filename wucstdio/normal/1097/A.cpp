#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
char s[10],t[5][10];
int main()
{
	scanf("%s%s%s%s%s%s",s,t[0],t[1],t[2],t[3],t[4]);
	for(int i=0;i<5;i++)
	{
		if(t[i][0]==s[0]||t[i][1]==s[1])
		{
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}