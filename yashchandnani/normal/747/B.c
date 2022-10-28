#include <stdio.h>
int main()
{
	int n;
	scanf("%d\n",&n);
	if (n%4!=0)
	{
		printf("===");
		return 0;
	}
	char a[n],b[5];
	for (int i = 0; i < 5; ++i)
	{
		b[i] = 0;
	}
	int t = n/4 ;
	for (int i = 0; i <n; ++i)
	{
		scanf("%c",&a[i]);
		if (a[i]=='A')
		{
			b[0]++;
			continue;
		}
		if (a[i]=='G')
		{
			b[1]++;
			continue;
		}
		if (a[i]=='T')
		{
			b[2]++;
			continue;
		}
		if (a[i]=='C')
		{
			b[3]++;
			continue;
		}
		b[4]++;
	}
	for (int i = 0; i < 4; ++i)
	{
		if(b[i]>t){
			printf("===");
			return 0;
		}
	}
	int i = 0;
	for (; b[0]<t; ++i)
	{	
		if (a[i]=='?')
		{
			printf("A");
			b[0]++;
		}
		else{
			printf("%c",a[i] );
		}
		
	}
	for (; b[1]<t; ++i)
	{	
		if (a[i]=='?')
		{
			printf("G");
			b[1]++;
		}
		else{
			printf("%c",a[i] );
		}
		
	}
	for (; b[2]<t; ++i)
	{	
		if (a[i]=='?')
		{
			printf("T");
			b[2]++;
		}
		else{
			printf("%c",a[i] );
		}
		
	}
	for (; b[3]<t; ++i)
	{	
		if (a[i]=='?')
		{
			printf("C");
			b[3]++;
		}
		else{
			printf("%c",a[i] );
		}
		
	}
	for(;i<n;i++){
		printf("%c",a[i] );

	}

	return 0;
}