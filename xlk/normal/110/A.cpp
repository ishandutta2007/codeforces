#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
char s[100];
int cnt;
int main()
{
	scanf("%s",s);
	for(int i = 0; s[i]; i++)
	if(s[i] == '7' || s[i] == '4')
	cnt++;
	if(!cnt)
	{
		puts("NO");
		return 0;
	}
	while(cnt)
	{
		if(cnt%10 != 7 && cnt%10 != 4)
		{
			puts("NO");
			return 0;
		}
		cnt /= 10;
		puts("YES");
	}
	return 0;

}