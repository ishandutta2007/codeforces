#include <bits/stdc++.h>
using namespace std;
const int Maxn=100005;
int a[Maxn],b[Maxn],n;
map <int,int> Ma;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),Ma[a[i]-a[i-1]]++;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		if(!Ma[b[i]-b[i-1]])
		{
			printf("No");
			return 0;
		}
		Ma[b[i]-b[i-1]]--;
	}
	if(b[1]!=a[1]) printf("No");
	else
		printf("Yes");
	return 0;
}