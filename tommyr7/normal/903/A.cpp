#include <bits/stdc++.h>
using namespace std;
int T,n;
bool check;
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		check=false;
		for (int i=0;i<=100;i++)
			for (int j=0;j<=100;j++)
				if (n==3*i+7*j) check=true;
		if (check) printf("YES\n"); else printf("NO\n");
	}
	return 0;
}