#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char s[100005];
int main()
{
	scanf("%s",s);
	printf("%d\n",(s[6]-'0')%2);
	return 0;
}