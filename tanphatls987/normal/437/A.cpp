#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <deque>

using namespace std;

const int maxi=100000;

int a[4],h[2][4],i,j,ans=0;
char s[101];
int main()
{
    for(i=0;i<4;i++)
    {
         scanf("%s",&s);
         a[i]=strlen(s)-2;
    }
    for(i=0;i<4;i++)
        for(j=0;j<4;j++) if (i!=j)
    {
        if (2*a[i]>a[j]) {h[0][i]=1;break;}
    }
    for(i=0;i<4;i++)
        for(j=0;j<4;j++) if (i!=j)
    {
        if (a[i]<2*a[j]) {h[1][i]=1;break;}
    }
    for(i=0;i<4;i++) if ((!h[0][i])||(!h[1][i])) ans+=1;
    if ((ans>1)||(!ans)) printf("C");else for(i=0;i<4;i++) if ((!h[0][i])||(!h[1][i])) printf("%c",i+'A');
}