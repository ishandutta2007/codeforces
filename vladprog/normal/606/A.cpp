#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c,x,y,z;
    scanf("%d%d%d%d%d%d",&a,&b,&c,&x,&y,&z);
    int l=0;
    if(a>x)
        l+=(a-x)/2,a=x;
    #define a b
    #define x y
    if(a>x)
        l+=(a-x)/2,a=x;
    #define a c
    #define x z
    if(a>x)
        l+=(a-x)/2,a=x;
    #undef a
    #undef x
    if(a+b+c+l>=x+y+z)
        printf("Yes");
    else
        printf("No");
}