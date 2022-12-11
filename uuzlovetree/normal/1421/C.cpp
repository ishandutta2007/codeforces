#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
char s[maxn];
int n;
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	puts("3");
	printf("L %d\n",2);
	printf("R %d\n",2);
	printf("R %d\n",2*n-1);
}