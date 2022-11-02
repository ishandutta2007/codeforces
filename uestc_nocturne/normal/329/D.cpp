/*
Author: elfness@UESTC
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int N=100;
char ret[N][N];
int X,Y;
int n,x;
int main()
{
    scanf("%d%d",&n,&x);
    X=32;Y=32;
    for(int i=0;i<N-1;i+=2)
    {
        for(int j=1;j<=X+1;j++)
        ret[i][j]='>';
        for(int j=X+2;j<X+2+2*Y;j+=2)
        ret[i][j]='.',ret[i][j+1]='>';
        for(int j=X+2+2*Y;j<N-1;j++)
        ret[i][j]='>';
        ret[i][N-1]='v';
    }
    for(int i=1;i<N-1;i+=2)
    {
        for(int j=N-1;j>=N-1-X;j--)
        ret[i][j]='<';
        for(int j=N-2-X;j>N-2-X-2*Y;j-=2)
        ret[i][j]='.',ret[i][j-1]='<';
        for(int j=N-2-X-2*Y;j>0;j--)
        ret[i][j]='<';
        ret[i][1]='v';
    }
    if(n==5)
    {
        puts(">...v");
        puts("v.<..");
        puts("..^..");
        puts(">....");
        puts("..^.<");
        printf("1 1\n");
    }
    else if(n==3)
    {
        puts(">vv");
        puts("^<.");
        puts("^.<");
        printf("1 3\n");
    }
    else
    {
        for(int i=1;i<N;i++)ret[N-1][i]='<';
        for(int i=1;i<N;i++)ret[i][0]='^';
        ret[0][0]='>';
        for(int i=0;i<N;i++,puts(""))
        for(int j=0;j<N;j++)printf("%c",ret[i][j]);
        printf("1 1\n");
    }
}