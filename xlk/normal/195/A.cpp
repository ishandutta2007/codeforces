#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int a,b,c;
int main()
{
    scanf("%d%d%d",&a,&b,&c);
    printf("%d\n",(int)ceil(1.0*(a-b)*c/b));
    return 0;
}