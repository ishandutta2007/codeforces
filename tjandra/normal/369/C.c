#include<stdio.h>
#include<stdlib.h>
typedef unsigned u;
typedef struct S
{
	char problem;
	u go;
	struct S *nx;
}v;
char vis[100000];
u ans[100000];
v *D[100000],*R[100000];
int main()
{
	u n,i,a,b,c;
	v *t;
	scanf("%u",&n);
	for(i=n;--i;)
	{
		scanf("%u%u%u",&a,&b,&c);
		a--;b--;
		t=(v*)malloc(sizeof(v));
		t->go=b;
		if(c==2)t->problem=1;
		else t->problem=0;
		t->nx=R[a];R[a]=t;
		t=(v*)malloc(sizeof(v));
		t->go=a;
		if(c==2)t->problem=1;
		else t->problem=0;
		t->nx=R[b];R[b]=t;
	}
	D[0]=R[0];vis[0]=1;
	for(i=a=0;;)
	{
		if(D[a]==NULL)
		{
			if(a==0)break;
			a--;
			if(D[a]->go==ans[i])i++;
			D[a]=D[a]->nx;
			continue;
		}
		if(vis[D[a]->go]){D[a]=D[a]->nx;continue;}
		vis[D[a]->go]=1;
		if(D[a]->problem){ans[i]=D[a]->go;}
		D[a+1]=R[D[a]->go];a++;
	}
	printf("%u\n",i);
	while(i--)printf("%u ",ans[i]+1);
	putchar('\n');
	return 0;
}