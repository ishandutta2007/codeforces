//By zzq
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
char s[666666];
int nn=0,nx[666666],ny[666666];
int sn=0,sx[666666],sy[666666];
inline int MD(int x,int y)
{
    bool am=x>y;
    for(int i=x;i<=y;i++)
    {
        if(!isdigit(s[i])) {am=1; break;}
    }
    if(x<y&&s[x]==48) am=1;
    if(am) ++sn, sx[sn]=x, sy[sn]=y;
    else ++nn, nx[nn]=x, ny[nn]=y;
}
int main()
{
    scanf("%s",s);
    int cp=0,ep=0;
    for(int i=0;s[i];i++)
    {
        ep=i;
        if(s[i]==','||s[i]==';')
        {
            MD(cp,i-1);
            cp=i+1;
        }
    }
    MD(cp,ep);
    if(nn==0) printf("-");
    else
    {
        printf("\"");
        for(int i=1;i<=nn;i++) s[ny[i]+1]=0, printf("%s%c",&s[nx[i]],(i==nn)?'"':',');
    }
    putchar(10);
    if(sn==0) printf("-");
    else
    {
        printf("\"");
        for(int i=1;i<=sn;i++) s[sy[i]+1]=0, printf("%s%c",&s[sx[i]],(i==sn)?'"':',');
    }
    putchar(10);
}