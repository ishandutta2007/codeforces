#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

struct edge
{int l,num,flag,val;
};
struct edge e[200010],e1[200010];

int n,m,n1,tot;
int a[200010],b[200010][3];

int read()
{int x=0;
 char ch=getchar();
 while(ch<48 || ch>57) ch=getchar();
 while(ch>=48 && ch<=57)
 {	x=x*10+ch-48;
 	ch=getchar();
 }
 return x;
}

bool cmp1(int A,int B)
{return e[A].val<e[B].val;
}

int main()
{int i,j,s=0;
 
 //scanf("%d%d",&n,&m);
 n=read();
 m=read();
 for(i=1;i<=m;i++)
 {	//scanf("%d%d",&e[i].l,&e[i].flag);
 	e[i].l=read();
 	e[i].flag=read();
	e[i].num=i;
	e[i].val=e[i].l*2-e[i].flag;
	s+=e[i].flag;
 	a[i]=i;
 }
 if(s!=n-1)
 {	printf("%d\n",-1);
 	return 0;
 }
 sort(a+1,a+m+1,cmp1);
 for(i=1;i<=m;i++)
	e1[i]=e[a[i]];
 memset(a,0,sizeof(a));	
 tot=1;
 n1=1;
 for(i=1;i<=m;i++)
 	if(e1[i].flag==1)
 	{	tot++;
 		b[e1[i].num][0]=tot-1;
 		b[e1[i].num][1]=tot;
 	}
 	else
 	{	while(a[n1]>=n1-2 && n1<=tot) n1++;
 		if(n1<=tot)
 		{	a[n1]++;
 			b[e1[i].num][0]=n1;
 			b[e1[i].num][1]=a[n1];
 		}
 		else
 		{	printf("%d\n",-1);
 			return 0;
 		}
 	}
 for(i=1;i<=m;i++)
 	printf("%d %d\n",b[i][0],b[i][1]);
 return 0;
}