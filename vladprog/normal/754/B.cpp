#include<bits/stdc++.h>

//#define DEBUG
#ifdef DEBUG
    #define IFD(X) X
#else
    #define IFD(X)
#endif // DEBUG

#define ll long long

using namespace std;

char c[4][5];

void f(int x1,int y1,int x2,int y2,int x3,int y3)
{
    int x=0;
    if(c[x1][y1]=='x')x++;
    if(c[x2][y2]=='x')x++;
    if(c[x3][y3]=='x')x++;
    int o=0;
    if(c[x1][y1]=='o')o++;
    if(c[x2][y2]=='o')o++;
    if(c[x3][y3]=='o')o++;
    if(x>=2&&o==0)
    {
        IFD(printf("(%d,%d),(%d,%d),(%d,%d) : x=%d o=%d ",
                   x1,y1,x2,y2,x3,y3,x,o);)
        printf("YES");
        exit(0);
    }
}

int main()
{
    scanf("%s%s%s%s",c[0],c[1],c[2],c[3]);
    for(int i=0;i<4;i++)
        for(int j=0;j<2;j++)
            f(i,j,i,j+1,i,j+2);
    for(int i=0;i<4;i++)
        for(int j=0;j<2;j++)
            f(j,i,j+1,i,j+2,i);
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            f(i,j,i+1,j+1,i+2,j+2);
    for(int i=2;i<4;i++)
        for(int j=0;j<2;j++)
            f(i,j,i-1,j+1,i-2,j+2);
    printf("NO");
}