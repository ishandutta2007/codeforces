#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i=0;i<n;i++)
			printf("%c",i%3+'a');
		puts("");
	}
	return 0;
}