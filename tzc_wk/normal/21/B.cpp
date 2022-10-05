#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream> 
using namespace std;
int main()
{
    int a1,b1,a2,b2;
    double c1,c2;
    cin>>a1>>b1>>c1>>a2>>b2>>c2;
    if((a1||b1)&&(a2||b2))
    {
        int gcd1=__gcd(a1,b1),gcd2=__gcd(a2,b2);
        a1/=gcd1,b1/=gcd1,c1=c1/(double)gcd1;
        a2/=gcd2,b2/=gcd2,c2=c2/(double)gcd2;
        if(a1==a2&&b1==b2&&c1==c2)
            printf("-1\n");
        else if(a1==a2&&b1==b2&&c1!=c2)
            printf("0\n");
        else
            printf("1\n");
    }
    else if(((!a1)&&(!b1)&&(c1))||((!a2)&&(!b2)&&(c2)))
        printf("0\n");
    else if(((!a1)&&(!b1)&&(!c1))||((!a2)&&(!b2)&&(!c2)))
        printf("-1\n");
    else
    	printf("0\n");
}