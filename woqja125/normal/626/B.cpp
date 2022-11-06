#include<stdio.h>
int main()
{
	char in[1001];
	int n, r, g, b, i, j;
	r=g=b=0;
	scanf("%d%s", &n, in);
	for(i=0; i<n; i++)
	{
		if(in[i] == 'R') r++;
		if(in[i] == 'G') g++;
		if(in[i] == 'B') b++;
	}
	if(r==0)
	{
		if(g==0) printf("B");
		else
		{
			if(b==0) printf("G");
			else
			{
				if(g>1 && b>1) printf("BGR");
				else if(g==1 && b==1) printf("R");
				else if(g==1) printf("GR");
				else printf("BR");
			}
		}
	}
	else
	{
		if(g==0)
		{
			if(b==0) printf("R");
			else
			{
				if(r>1 && b>1) printf("BGR");
				else if(r==1 && b==1) printf("G");
				else if(r==1) printf("GR");
				else printf("BG");
			}
		}
		else
		{
			if(b==0)
			{
				if(r>1 && g>1) printf("BGR");
				else if(r==1 && g==1) printf("B");
				else if(r==1) printf("BR");
				else printf("BG");
			}
			else printf("BGR");
		}
	}
	return 0;
}