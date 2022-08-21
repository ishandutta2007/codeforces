#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int n,s=0,a,b,c;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        if(a+b+c>=2) s++;
    }
    printf("%d",s);
}