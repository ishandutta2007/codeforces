#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,x;
    scanf("%d%d",&n,&m);
    if(n>m)
		swap(n,m);
    if(n==1)
		x=m/3+(m%3!=0);
    else if(n==2)
		x=m/2+1;
    else if(n==3)
		x=m-(m-1)/4;
    else if(n==4)
		x=(m+1)-(m==4||m==7||m==8||m==10);
    else if(n==5)
		x=7*(m==5)+8*(m==6)+9*(m==7)+11*(m==8);
    else if(n==6)
		x=10;
    printf("%d\n",n*m-x);
    return 0;
}
///////////////