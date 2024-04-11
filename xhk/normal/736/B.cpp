#include<bits/stdc++.h>
using namespace std;

int n,ans;

int check(int N)
{int i,flag;

 flag=1;
 for(i=2;i*i<=N;i++)
 	if(N%i==0)
	{	flag=0;
		break;
	}
 return flag;
}

int main()
{int i,j;
 
 scanf("%d",&n);
 if(n<=11)
 {	if(n==2)
 		ans=1;
 	else if(n==3)
 		ans=1;
 	else if(n==4)
 		ans=2;
 	else if(n==5)
 		ans=1;
 	else if(n==6)
 		ans=2;
 	else if(n==7)
 		ans=1;
 	else if(n==8)
	 	ans=2; // 3+5
	else if(n==9)
		ans=2;
	else if(n==10)
		ans=2;
	else if(n==11)
		ans=1;
 	printf("%d\n",ans);
 	return 0;
 }
 if(n%2==0)
 {	printf("%d\n",2);
 	return 0;
 }
 if(check(n))
 {	printf("%d\n",1);
 	return 0;
 }
 if(check(n-2))
 {	printf("%d\n",2);
 	return 0;
 }
 printf("%d\n",3);
 return 0;
}