#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int n,l;
int c[1000010];
char a[1000010];

int main()
{int i,j,k,flag,last,mi,ma,s;
 char ch;
 
 scanf("%d",&n);
 for(i=1;i<=n;i++) scanf("%d",&c[i]);
 getchar();
 flag=1;
 for(i=1;i<=n;i++)
 {	l=0;
 	ch=getchar();
 	while(ch!='\n')
 	{	a[++l]=ch;
 		ch=getchar();
 	}
 	mi=0;
 	ma=0;
 	for(j=1;j<=l;j=last+1)
 	{	last=j;
 		while(last+1<=l && a[last+1]!=' ') last++;
 		s=0;
 		for(k=j;k<=last;k++)
 			if(a[k]=='a' || a[k]=='e' || a[k]=='i' || a[k]=='o' || a[k]=='u' || a[k]=='y')
 				s++;
 		if(s>0)
 		{	//mi++;
 			ma+=s;
 		}
 	}
 	//if(c[i]<mi || c[i]>ma) flag=0;
 	if(c[i]!=ma) flag=0;
 }
 if(flag)
 	printf("YES\n");
 else
 	printf("NO\n");
 return 0;
}