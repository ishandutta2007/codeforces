#include<bits/stdc++.h>
using namespace std;

int ans[100010],ansn;

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int la=0;
	ans[ansn=1]=0;
	for (int i=0; i<k-1; i++)
	{
		ans[++ansn]=i;
		for (int j=k-1; j>i; j--) ans[++ansn]=j,ans[++ansn]=i;
		ansn--;
	}
	ans[++ansn]=k-1;
	for (int i=k-2; i>=0; i--) ans[++ansn]=i;
	for (int i=1,p=1; i<=n; i++,p++)
	{
		if (p>ansn) p-=(ansn-1);
		putchar(ans[p]+'a');
	}
	return 0;
}