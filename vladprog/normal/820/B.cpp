#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,a;
    scanf("%d%d",&n,&a);
    int mv=0;
    double ma=360;
    double d=(double)180/n;
    double ta=d;
    for(int i=n-1;i>=2;i--,ta+=d)
        if(ma>(abs(180-abs(180-ta)-a)))
            mv=i,ma=abs(180-abs(180-ta)-a);
    printf("%d 1 %d",n,mv);
}