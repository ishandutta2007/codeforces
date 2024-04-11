#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,can=1,a,b;
		scanf("%d%d%d",&n,&a,&b);
		if(a<b)
			can=0;
		for(int i=2;i<=n;i++)
		{
			int c,d;
			scanf("%d%d",&c,&d);
			int e=c-a,f=d-b;
			if(e<0||f<0||e<f)
				can=0;
			a=c,b=d;
		}
		puts(can?"YES":"NO");
	}
	return 0;
}