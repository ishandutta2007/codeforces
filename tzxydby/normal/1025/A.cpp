#include<bits/stdc++.h>
using namespace std;
int sum[26];
int main()
{
	int n,k=0;
	scanf("%d",&n);
	if(n==1)
	{
		printf("YES\n");
		return 0;
	}
	getchar();
	for(int i=1;i<=n;i++)
	{
		char c=getchar();
		sum[c-'a']++;
	}
	for(int i=0;i<26;i++)
		if(sum[i]>1)
			k++;
	if(k)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}