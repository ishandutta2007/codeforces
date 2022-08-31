#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
int main() 
{
    int n,c=0;
    char a[100],la=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",a);
        if(a[0]!=la) c++,la=a[0];
    }
    printf("%d",c);
}