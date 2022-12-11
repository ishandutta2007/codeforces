#include<bits/stdc++.h>
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		bool f1=false,f2=false;
		while(n--)
		{
			int x;
			scanf("%d",&x);
			if(x&1) f1=true;
			else f2=true;
		}
		if(f1&&f2) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}