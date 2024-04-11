#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int a[30],n;
int main()
{
	scanf("%d",&n);
	for(int i = 1;i <= n; i++)
		for(int j = 'a'; j <= 'z'; j++)
		if(!a[j-'a'] || i == a[j-'a'] + 4 || i == a[j-'a'] + 7)
		{
			printf("%c",j);
			a[j-'a'] = i;
			break;
		}
	return 0;

}