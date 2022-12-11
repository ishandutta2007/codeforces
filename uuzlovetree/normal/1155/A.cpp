#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
char s[300005];
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<n;++i)if(s[i]>s[i+1])
	{
		puts("YES");
		printf("%d %d\n",i,i+1);
		return 0;
	}
	puts("NO");
	return 0;
}