//By zzq
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
char S[233333];
int g[999],s[999],sn=0;
int main()
{
    scanf("%s",S);
    for(int i=0;S[i];i++) g[S[i]]++;
    for(int i='a';i<='z';i++)
    {
        if(g[i]&1) s[++sn]=i;
    }
    int sp=sn/2;
    if(sn&1) ++sp;
    for(int i=1;i<=sn/2;i++) g[s[i]]++, g[s[i+sp]]--;
    for(int i='a';i<='z';i++)
    {
        if(g[i]&1)
        {
            for(int j=1;j<=g[i]/2;j++) putchar(i);
        }
        else
        {
            for(int j=1;j<=g[i]/2;j++) putchar(i);
        }
    }
    for(int i='a';i<='z';i++)
    {
        if(g[i]&1) putchar(i);
    }
    for(int i='z';i>='a';i--)
    {
        for(int j=1;j<=g[i]/2;j++) putchar(i);
    }
}