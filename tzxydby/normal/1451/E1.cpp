#include<bits/stdc++.h>
using namespace std;
int n,a[1<<17],A,B,C,D,E,F;
int query(int i,int j,int ty) 
{
	if(ty==0) printf("AND");
	else if(ty==1) printf("OR");
	else printf("XOR");
	printf(" %d %d\n",i,j);
	fflush(stdout);
	int v;
	scanf("%d",&v);
	return v;
}
int main()
{
	scanf("%d",&n);
	D=query(1,2,0);
	E=query(1,3,0);
	F=query(2,3,0);
	A=query(1,2,2);
	B=query(1,3,2);
	C=A^B;
	A+=2*D;
	B+=2*E;
	C+=2*F;
	a[1]=(A+B-C)/2;
	a[2]=A-a[1];
	a[3]=B-a[1];
	for(int i=4;i<=n;i++) a[i]=query(1,i,2)^a[1];
	printf("!");
	for(int i=1;i<=n;i++) printf(" %d",a[i]);puts("");
}