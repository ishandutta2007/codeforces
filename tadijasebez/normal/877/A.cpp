#include <stdio.h>
#include <cstring>
int sol;
char a[1000];
char f[5][15];
int main()
{
	int n,i,j;
	scanf("%s",&a);
	f[0][0]='D';
	f[0][1]='a';
	f[0][2]='n';
	f[0][3]='i';
	f[0][4]='l';
	f[1][0]='O';
	f[1][1]='l';
	f[1][2]='y';
	f[1][3]='a';
	f[2][0]='S';
	f[2][1]='l';
	f[2][2]='a';
	f[2][3]='v';
	f[2][4]='a';
	f[3][0]='A';
	f[3][1]='n';
	f[3][2]='n';
	f[4][0]='N';
	f[4][1]='i';
	f[4][2]='k';
	f[4][3]='i';
	f[4][4]='t';
	f[4][5]='a';
	n=(unsigned) strlen(a);
	for(i=0;i<n;i++)
	{
		int ok=1;
		for(j=0;j<5;j++) if(a[i+j]!=f[0][j]) ok=0;
		sol+=ok;
		ok=1;
		for(j=0;j<4;j++) if(a[i+j]!=f[1][j]) ok=0;
		sol+=ok;
		ok=1;
		for(j=0;j<5;j++) if(a[i+j]!=f[2][j]) ok=0;
		sol+=ok;
		ok=1;
		for(j=0;j<3;j++) if(a[i+j]!=f[3][j]) ok=0;
		sol+=ok;
		ok=1;
		for(j=0;j<6;j++) if(a[i+j]!=f[4][j]) ok=0;
		sol+=ok;
	}
	if(sol==1) printf("YES\n");
	else printf("NO\n");
	return 0;
}