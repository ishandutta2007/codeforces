#include <stdio.h>

char s[12][3];

int distance(char *c1, char *c2)
{
	int ind1, ind2, i;
	for(i=0; i<12; i++)
		if (c1[0]==s[i][0] && c1[1]==s[i][1]) {ind1=i; break;}
	for(i=0; i<12; i++)
		if (c2[0]==s[i][0] && c2[1]==s[i][1]) {ind2=i; break;}
	return (ind2>=ind1? ind2-ind1: 12-(ind1-ind2));
}

int main()
{
	char c[3][3];
	scanf("%s %s %s", &c[0], &c[1], &c[2]);
	int m[6][3], i, j, k, top, tmp1, tmp2;
	top=0;
	for(i=0; i<12; i++) 
		for(j=0; j<3; j++) s[i][j]=0;
	s[0][0]='C';
	s[1][0]='C'; s[1][1]='#';
	s[2][0]='D';
	s[3][0]='D'; s[3][1]='#';
	s[4][0]='E';
	s[5][0]='F';
	s[6][0]='F'; s[6][1]='#';
	s[7][0]='G';
	s[8][0]='G'; s[8][1]='#';
	s[9][0]='A';
	s[10][0]='B';
	s[11][0]='H';
	for(i=0; i<3; i++)
		for(j=0; j<3; j++)
		{
			if (j==i) continue;
			k=3-i-j;
			m[top][0]=i; m[top][1]=j; m[top][2]=k; top++;
		}
	for(i=0; i<6; i++)
	{
		tmp1=distance(c[m[i][0]], c[m[i][1]]);
		tmp2=distance(c[m[i][1]], c[m[i][2]]);
		if (tmp1==3 && tmp2==4) {printf("minor"); return 0;}
		if (tmp1==4 && tmp2==3) {printf("major"); return 0;}
	}
	printf("strange");
}