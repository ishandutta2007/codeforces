#include<stdio.h>
typedef unsigned u;
u A[26];
int main()
{
	u i,j,k;char c,C='0';
	while((c=getchar())<'a');
	do ++A[c-'a'];
	while((c=getchar())>='a');
	i=0;j=25;
	while(1)
	{
		while(i<j&&!(A[i]&1))++i;
		while(j>i&&!(A[j]&1))--j;
		if(i==j)break;
		++A[i];--A[j];
	}
	for(i=-1;++i<26;)if(A[i]&1){C=i+'a';--A[i];}
	for(i=-1;++i<26;)for(k=A[i]>>1;k--;)putchar(i+'a');
	if(C!='0')putchar(C);
	while(i--)for(k=A[i]>>1;k--;)putchar(i+'a');
	putchar('\n');
	return 0;
}