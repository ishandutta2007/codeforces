#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

char a[110],b[110];

int calc(char a[])
{if(a[1]=='m' && a[2]=='o' && a[3]=='n')
	return 1;
 else if(a[1]=='t' && a[2]=='u' && a[3]=='e')
 	return 2;
 else if(a[1]=='w' && a[2]=='e' && a[3]=='d')
 	return 3;
 else if(a[1]=='t' && a[2]=='h' && a[3]=='u')
 	return 4;
 else if(a[1]=='f' && a[2]=='r' && a[3]=='i')
 	return 5;
 else if(a[1]=='s' && a[2]=='a' && a[3]=='t')
 	return 6;
 else
 	return 7;
}

int main()
{int i,j,x,y,z;
 
 scanf("%s",a+1);
 scanf("%s",b+1);
 x=calc(a);
 y=calc(b);
 z=(y-x+7)%7;
 if(z==0 || z==2 || z==3)
 	printf("YES\n");
 else
 	printf("NO\n");
 return 0;
}