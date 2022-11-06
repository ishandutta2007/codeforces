#include<stdio.h>
char d[2][10000];
int main()
{
	int n, i, j, c = 0;
	scanf("%d", &n);
	scanf("%s", d[0]+1);
	for(i=0; i<=n; i++)
	{
		char *dat = d[i%2], *dat2 = d[(i+1)%2];
		for(j=1; j<=n; j++)
		{
			dat2[j] = dat[j];
			if(dat[j] != '.') continue;
			if(dat[j-1] == 'R' && dat[j+1] == 'L') continue;
			if(dat[j-1] == 'R') dat2[j] = 'R';
			else if(dat[j+1] == 'L') dat2[j] = 'L';
		}
	}
	for(i=1; i<=n; i++)if(d[(n+1)%2][i] == '.')c++;
	printf("%d", c);
	return 0;
}