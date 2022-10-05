#include <bits/stdc++.h>
using namespace std;
const int Maxn=105;
int a[Maxn],ans;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i<<=1)
		for(int j=1;j<=n;j+=i)
		{
			for(int k=j+1;k<=j+i-1;k++)
				if(a[k-1]>a[k]) goto A;
			ans=max(ans,i);
			A:;
		}
	printf("%d",ans);
	return 0;
}