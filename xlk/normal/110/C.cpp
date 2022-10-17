#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;
int n,x;
inline bool check()
{
    if(n<4*x) return 1;
    if((n-4*x)%7==0) return 0;
    return 1;
}
int main()
{
    scanf("%d",&n);
    while(check()&&x<n) x++;
    if(x==n) printf("-1\n");
    else
    {
        for(int i=1;i<=x;i++)
            printf("4");
        for(int i=1;i<=(n-4*x)/7;i++)
            printf("7");
        printf("\n");
    }
    return 0;
}