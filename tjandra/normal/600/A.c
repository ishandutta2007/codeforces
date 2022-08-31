#include<stdio.h>
typedef unsigned u;
char A[111111],B[111111],S[111111];u Ai,Bi;
void pu(u l,u r,char *X,u *Xi)
{
	while(++l<r)X[(*Xi)++]=S[l];
	X[(*Xi)++]=',';
	return;
}
u isdig(u l,u r)
{
	if(l+1==r)return 0;
	if(l+2==r&&S[l+1]=='0')return 1;
	if(S[l+1]=='0')return 0;
	while(++l<r)if(S[l]<'0'||S[l]>'9')return 0;
	return 1;
}
void scn(u l)
{
	u r=l;
	while(S[++r]&&S[r]!=';'&&S[r]!=',');
	if(isdig(l,r))pu(l,r,A,&Ai);
	else pu(l,r,B,&Bi);
	if(S[r])scn(r);
	return;
}
int main()
{
	scanf("%s",S);
	scn(-1);
	if(Ai){A[--Ai]='\0';printf("\"%s\"\n",A);}
	else printf("-\n");
	if(Bi){B[--Bi]='\0';printf("\"%s\"\n",B);}
	else printf("-\n");
	return 0;
}