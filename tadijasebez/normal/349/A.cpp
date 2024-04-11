#include <stdio.h>
const int N=100050;
int b,c,a[N];
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&a[i]);
		if(a[i]==25) b++;
		if(a[i]==50){ if(!b) return printf("NO\n"),0;b--;c++;}
		if(a[i]==100)
		{
			if(!b) return printf("NO\n"),0;
			if(c) c--,b--;
			else
			{
				if(b<3) return printf("NO\n"),0;
				b-=3;
			}
		}
	}
	printf("YES\n");
	return 0;
}